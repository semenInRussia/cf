// semenInRussia 2024
// https://acm.timus.ru/problem.aspx?space=1&num=1269
#include <cassert>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
using namespace std;

const int TRIE_SIZE = 1e4;
char AL = CHAR_MAX;
int sz = 1;
int link[TRIE_SIZE], out[TRIE_SIZE];
map<char, int> to[TRIE_SIZE];

void add(string &s) {
  int v = 0;
  for (auto ch : s) {
    if (!to[v][ch]) {
      out[sz] = -1;
      to[v][ch] = sz++;
      assert(sz < TRIE_SIZE);
    }
    v = to[v][ch];
  }
  // cout << "ADded " << s << " as " << v << '\n';
  out[v] = int(s.size());
}

void clear() {
  for (int i = 0; i < sz; i++)
    to[i].clear();
  for (int i = 0; i < sz; i++)
    link[i] = 0;
  sz = 1;
}

void push_links() {
  queue<int> q;
  q.push(0);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    int u = link[v];
    for (char c = 0; c < AL; c++) {
      // link(u) = go(link(u.p), c)
      if (to[v][c]) {
        link[to[v][c]] = v ? to[u][c] : 0;
        q.push(to[v][c]);
      } else {
        // go(v, c) = go(link(v), c)
        to[v][c] = to[u][c];
      }
    }
  }
}

int match(int v) {
  if (out[v] != -1)
    return out[v];
  return out[v] = match(link[v]);
}

// string g;
// void bfs(int v) {

// }

const int N = 1e4, B = N / 10;
string dict[N];
vector<string> text;
int main() {
  int n;
  cin >> n;
  cin.ignore();
  for (int i = 0; i < n; i++)
    getline(cin, dict[i]);

  int m;
  cin >> m;
  cin.ignore();
  text.resize(m);
  for (int i = 0; i < m; i++)
    getline(cin, text[i]);

  bool found = 0;
  pair<int, int> ans = {m, int(1e9)};
  for (int b = 0; b * B <= n; b++) {
    // add words of block; dict: [b*B; (b+1)*B)
    for (int i = b * B; i < min(n, B * (b + 1)); i++) {
      assert(i < N);
      add(dict[i]);
    }
    push_links();
    for (int i = 0; i < ans.first; i++) {
      int v = 0, j = 0;
      for (char ch : text[i]) {
        v = to[v][ch];
        if (match(v)) {
          ans = min(ans, {i + 1, j - match(v) + 2});
          found = 1;
        }
        j++;
      }
    }

    clear();
  }

  if (found)
    cout << ans.first << ' ' << ans.second;
  else
    cout << "Passed";
}
