// semenInRussia 2025
#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iostream>

using namespace std;
using ll = long long;

void solve() {
  ll n, a, b;
  cin >> n >> a >> b;

  if (n == 1) {
    cout << "0\n";
    return;
  }

  ll ans = n;

  ll df = abs(a - b);

  for (auto d : {df, n - df}) {
    if (d == 0) {
      ans = n / 2;
      break;
    }

    ll l = d - 2;
    ll r = max(d, n - d);

    while (r - l > 1) {
      ll m = (r - l) / 2 + l;
      assert(m >= d - 1);
      ll t = max(m - max(0ll, d - 1) * 2, 0ll);
      ll t2 = m - (n - d - 1 - m) * 2;
      if (t + m >= n - d - 1 || t2 >= d - 1) {
        r = m;
      } else {
        l = m;
      }
    }

    ans = min(ans, r);
  }

  cout << max(ans, 0ll);
}

int main() {
  int tt = 1;
#ifdef home
  cin >> tt;
#endif
  while (tt--) {
    solve();
    cout << '\n';
  }
}
