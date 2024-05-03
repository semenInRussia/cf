// Copyright 2024 semenInRussia

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

using ll = long long;
using ull = unsigned long long;
const int inf = 1e9;
const int maxn = 2e5;

void solve() {
  int n, m;
  cin >> n >> m;
  string a, b;
  cin >> a >> b;

  // alg:
  // i - a cursor (prefix)
  // j - b cursor ()

  // for every i move j cursor which can be substring of a

  int j = 0, ans = -1;
  for (int i = 0; i < n; i++, j++) {
    for (; j < m; j++)
      if (b[j] == a[i])
        break;
    if (j == m)
      break;
    else
      ans = i;
  }

  cout << (ans + 1) << '\n';
}

int main() {
  int tt;
  cin >> tt;
  while (tt--)
    solve();
}
