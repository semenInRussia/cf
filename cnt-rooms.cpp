// Copyright 2024 semenInRussia

#include <iostream>
using namespace std;

const int maxn = 1000;
string t[maxn];
int n, m;
bool used[maxn][maxn];

void dfs(int i, int j) {
  if (i < 0 || i >= n || j < 0 || j >= m || used[i][j] || t[i][j] == '#')
    return;

  used[i][j] = true;
  for (int d : {+1, -1}) {
    dfs(i, j + d);
    dfs(i + d, j);
  }
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> t[i];

  int ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (!used[i][j] && t[i][j] == '.')
        dfs(i, j), ans++;

  cout << ans << '\n';
}
