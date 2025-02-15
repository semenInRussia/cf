// semenInRussia 2024
#include <cstdint>
#include <iostream>
using namespace std;

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int64_t s, k;
    cin >> s >> k;

    // last m; 1 + (1 + k) + (1 + 2k) <= s

    __int128_t l = 0;
    __int128_t r = 1e12;

    while (r - l > 1) {
      auto m = (r - l) / 2 + l;
      auto c = m * (1ll + (1ll + (m - 1ll) * k)) / 2;

      if (c <= s) {
        l = m;
      } else {
        r = m;
      }
    }

    cout << (long long)l << "\n";
  }
}
