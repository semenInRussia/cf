// Copyright 2024 semenInRussia
// https://codeforces.com/problemset/problem/1955/G
// #dp *1900

#include <algorithm>
#include <iostream>

#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")

using namespace std;
using ll = long long;

const int maxn = 105;
ll a[maxn][maxn], d[maxn][maxn];
int m, n;

ll mx = 1;
void dfs(int i, int j, ll g) {
  if (i == n || j == m || g <= mx)
    return;
  if (i == n - 1 && j == m - 1) {
    mx = max(g, mx);
    return;
  }

  g = __gcd(g, a[i][j]);
  if (d[i][j] % g == 0)
    return;
  d[i][j] = g;
  dfs(i + 1, j, g);
  dfs(i, j + 1, g);
}

int main() {
  int tt;
  cin >> tt;
  cin.tie(0);
  while (tt--) {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        cin >> a[i][j], d[i][j] = 1;
    mx = 1;
    dfs(0, 0, __gcd(a[0][0], a[n - 1][m - 1]));
    cout << mx << endl;
  }
}
