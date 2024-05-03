// Copyright 2024 semenInRussia

#include <algorithm>
using namespace std;

#include <iostream>
#include <vector>

using ll = long long;

void setmax(ll &var, ll x) { var = max(var, x); }

int main() {
  int n, s;
  cin >> n >> s;

  vector<ll> t(n + 1), l(n + 1);
  for (int i = 0; i < n; i++)
    cin >> t[i] >> l[i];

  vector<vector<ll>> d(n, vector<ll>(s + 1, 0));
  // d[k][i] -- the best way to do < i, if use only <= k
  for (int k = 0; k < n; k++) {
    for (int i = 0; i <= s; i++) {
      d[k][i] = k && d[k - 1][i];
      if (k && i >= l[k]) {
        setmax(d[k][i], d[k - 1][i - l[k]]);
      }
    }
  }

  for (auto &row : d) {
    for (auto el : row)
      cout << el << ' ';
    cout << '\n';
  }

  cout << d.back().back() << endl;
}
