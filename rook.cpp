// Copyright 2024 semenInRussia
// cf https://codeforces.com/problemset/problem/1957/C
// #dp #combinatorics *1600

#include <iostream>

using ll = long long;
using namespace std;

const ll mod = 1e9 + 7;
const int maxn = 3e5;
ll d[maxn];

void solve() {
  int n, k;
  cin >> n >> k;

  ll m = n; // free rows/cols
  for (int i = 0; i < k; i++) {
    int r, c;
    cin >> r >> c;
    if (r == c)
      m--;
    else
      m -= 2;
  }

  d[0] = 1, d[1] = 1;
  for (int i = 2; i <= m; i++) {
    d[i] = d[i - 1] + (2ll * (i - 1) * d[i - 2]) % mod;
    d[i] %= mod;
  }

  cout << d[m] << endl;
}

int main() {
  int tt;
  cin >> tt;
  while (tt--)
    solve();
}
