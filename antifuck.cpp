// semenInRussia 2024
// https://acm.timus.ru/problem.aspx?space=1&num=1269
#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// N is size of alphabet
int sz = 0;
struct node {
  unordered_map<char, int> go, to;
  int link = -1, p = -1;
  short out = -1;
  char ch = -1;

  node(char ch = -1, int p = -1) : p(p), ch(ch) {}
};

unordered_map<int, node> t;

int add(string &s) {
  int v = 0;
  for (auto ch : s) {
    if (!t[v].to.count(ch)) {
      t[v].to[ch] = sz;
      t[sz++] = node(ch, v);
    }
    v = t[v].to[ch];
  }
  t[v].out = s.size();
  return v;
}

int go(int v, char ch);

int link(int v) {
  node &e = t[v];
  int &lnk = e.link;
  if (lnk != -1)
    return lnk;
  if (e.p == 0 || v == 0)
    return lnk = 0;
  return lnk = go(link(e.p), e.ch);
}

int go(int v, char ch) {
  node &e = t[v];
  if (t[v].to.count(ch))
    return t[v].to[ch];
  if (t[v].go.count(ch))
    return t[v].go[ch];
  int &res = t[v].go[ch];
  if (v == 0)
    return res = 0;
  return res = go(link(v), ch);
}

// return the maximum size of a "Bad Word" which is inside the v state
short out(int v) {
  node &e = t[v];
  if (e.out != -1)
    return e.out;
  if (v == 0)
    return 0;
  return e.out = out(link(v));
}

int main() {
  t[0].out = 0;
  sz = 1;

  int n;
  cin >> n;
  cin.ignore();
  string w;
  for (int i = 0; i < n; i++) {
    getline(cin, w);
    add(w);
    w.clear();
  }

  int m;
  cin >> m;
  cin.ignore();
  bool found = false;
  pair<int, int> ans = {m + 1, 0};
  for (int i = 1; i <= m && !found; i++) {
    int v = 0;
    char ch = getchar();
    int j = 0;
    while (ch != '\n') {
      v = go(v, ch);
      if (out(v)) {
        ans = min(ans, {i, j - out(v) + 2});
        found = true;
      }
      ch = getchar();
      j++;
    }
  }
  if (found)
    cout << ans.first << ' ' << ans.second;
  else
    cout << "Passed";
}
