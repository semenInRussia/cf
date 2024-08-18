// Copyright 2024 semenInRussia
// https://cses.fi/problemset/task/1666
#include <iostream>
#include <vector>

using namespace std;

const int maxn = 1e5;
vector<int> g[maxn];
int c[maxn];

void dfs(int i, int num) {
  c[i] = num;
  for (auto j : g[i])
    if (!c[j])
      dfs(i, num);
}

int main() {
  int n, m;
  cin >> n >> m;
  while (m--) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  int ans = 0;
  for (int i = 0; i < n; i++)
    if (!c[i])
      dfs(i, ++ans);

  cout << ans << endl;
}
