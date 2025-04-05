// semenInRussia 2025
#include <cstdint>
#include <iostream>

using namespace std;

const int N = 60;

int main() {
  int64_t n;
  cin >> n;

  int ans = 0;

  for (int l = 0; l < N; l++) {
    for (int r = l + 1; r <= N; r++) {
      int64_t cur = 0;
      for (int j = l; j < r; j++) {
        cur ^= 1ll << j;
      }
      // if (cur <= n) {
      //   cout << cur << "\n";
      // }
      ans += cur <= n;
    }
  }

  cout << ans;
}
