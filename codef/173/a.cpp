// semenInRussia 2024
#include <cstdint>
#include <iostream>

using namespace std;

void solve() {
  int64_t n;
  cin >> n;

  int64_t ans = 1;

  while (n > 3) {
    ans *= 2;
    n /= 4;
  }

  cout << ans << "\n";
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
