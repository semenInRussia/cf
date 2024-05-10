// Copyright 2024 semenInRussia

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9 + 7;

void solve() {
  int n, k, q;
  cin >> n >> k >> q;
  vector<ll> a(k + 1, 0), b(k + 1, 0);
  for (int i = 1; i <= k; i++)
    cin >> a[i];
  for (int i = 1; i <= k; i++)
    cin >> b[i];

  while (q--) {
    ll d;
    cin >> d;

    if (d == 0) {
      cout << "0 ";
      continue;
    }

    // next sign
    int i = lower_bound(a.begin(), a.end(), d) - a.begin();
    ll s = a[i - 1] - a[i];
    ll t = b[i - 1] - b[i];

    ll x = ((d - a[i - 1]) * t) / s;
    x += b[i - 1];
    cout << x << ' ';
  }
  cout << '\n';
}

int main() {
  int tt;
  cin >> tt;
  while (tt--)
    solve();
}
