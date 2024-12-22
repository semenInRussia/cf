// semenInRussia 2024
// http..
#include <cstdint>
#include <iostream>
using namespace std;

void solve() {
  int k, l1, r1, l2, r2;
  cin >> k >> l2 >> r2 >> l1 >> r1;
  r2++;

  int64_t x = 1;

  int64_t ans = 0;

  while (x <= r1 + 10) {
    auto v = (l1 + x - 1) / x;
    auto v2 = (r1 / x) + 1;

    auto a = max(1ll * l2, v);
    auto b = min(1ll * r2, v2);

    if (a < b) {
      ans += max(b - a, 0ll);
    }

    x *= k;
  }

  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
