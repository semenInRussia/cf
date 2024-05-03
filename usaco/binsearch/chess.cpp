// Copyright 2024 semenInRussia

#include <iostream>
#include <vector>

using ll = long long;
using ull = unsigned long long;
const int inf = 1e9 + 7;

using namespace std;

const int maxn = 1e3;
string t[maxn];

int main() {
  int m, n;
  cin >> m >> n;
  for (int i = 0; i < n; i++)
    cin >> t[i];

  int ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      ans += t[i][j] == 'W';

  cout << ans << '\n';
}
