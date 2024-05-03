// Copyright 2024 semenInRussia

#include <iostream>
#include <vector>

using namespace std;
using ull = unsigned long long;

const ull MOD = 998244353ULL;

int main() {
  int n, m;
  cin >> n >> m;

  vector<string> t(n);
  for (auto &row : t)
    cin >> row;

  vector<vector<ull>> d(n, vector<ull>(m, 0));
  d[0][0] = 1ULL;
  for (int i = 1; i < n; i++)
    d[i][0] = (d[i - 1][0] * (t[i][0] == '.')) % MOD;
  for (int j = 1; j < m; j++)
    d[0][j] = (d[0][j - 1] * (t[0][j] == '.')) % MOD;
  for (int i = 1; i < n; i++)
    for (int j = 1; j < m; j++)
      d[i][j] = ((d[i - 1][j] + d[i][j - 1]) * (t[i][j] == '.')) % MOD;

  cout << d.back().back() << endl;

  return 0;
}
