// semenInRussia 2025
#include <cstdint>
#include <iostream>

using namespace std;

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k, p;
    cin >> n >> k >> p;
    k = abs(k);
    int ans = (k + p - 1) / p;
    if (ans > n) {
      ans = -1;
    }
    cout << ans << "\n";
  }
}
