// semenInRussia 2024
//
#include <cstdint>
#include <iostream>
using namespace std;

void solve() {
  int n, a, b, c;
  cin >> n >> a >> b >> c;

  int64_t l = -1;
  int64_t r = n + 1;

  while (r - l > 1) {
    auto m = (r + l) / 2;

    auto cur =
        a * ((m + 2) / 3) + b * max(0ll, (m + 1) / 3) + c * max(0ll, m / 3);

    if (cur >= n) {
      r = m;
    } else {
      l = m;
    }
  }

  cout << r << "\n";
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
