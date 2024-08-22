// semenInRussia 2024
// https://cses.fi/problemset/task/1676
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int N = 2e5;
vector<int> g[N], t[N];
int answ[N], o[N];
bool used[N];
int tim = 0;

void dfs(int x) {
  used[x] = 1;
  for (int y : g[x]) {
    if (!used[y]) {
      dfs(y);
    }
  }
  o[tim++] = x;
}

void dfs2(int x, int num) {
  answ[x] = num;
  for (int y : t[x]) {
    if (!answ[y]) {
      dfs2(y, num);
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
    t[b].push_back(a);
  }

  // topsort
  for (int i = 0; i < n; i++) {
    if (!used[i]) {
      dfs(i);
    }
  }
  reverse(o, o + n);

  // fill answ[]
  int num = 0; // cnt
  for (int i = 0; i < n; i++) {
    int x = o[i];
    if (!answ[x]) {
      dfs2(x, num + 1);
      num++;
    }
  }

  cout << num << '\n';
  for (int i = 0; i < n; i++) {
    cout << answ[i] << ' ';
  }
}
