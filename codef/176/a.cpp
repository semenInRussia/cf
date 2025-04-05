// semenInRussia 2025
#include <cassert>
#include <cstdint>
#include <iostream>

using namespace std;

int main() {
  int tt = 1;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;

    int ans = 0;
    if (n & 1) {
      ++ans;
      n -= k;
    }

    int l = (n + k - 2) / (k - 1);
    ans += l;

    cout << ans << "\n";
  }
}
