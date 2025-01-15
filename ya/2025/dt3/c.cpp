// semenInRussia 2025
#include <cstdint>
#include <iostream>

using namespace std;

int main() {
  int l, r;
  cin >> l >> r;

  // if (l == 0) {
  //   cout << (r - l + 1) * 1ll * (r - l + 1) << "\n";
  //   return 0;
  // }

  int64_t ans = 0;

  for (int x = l; x <= r; x++) {
    for (int y = l; y <= r; y++) {
      int z = x & ~y;
      bool ok = (l <= z && z <= r);
      // if (ok) {
      //   cout << x << " " << y << " " << z << "\n";
      // }
      ans += ok;
    }
  }

  cout << ans << "\n";
}
