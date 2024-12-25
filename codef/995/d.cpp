// semenInRussia 2024
//
#include <algorithm>
#include <cstdint>
#include <iostream>
using namespace std;

const int N = 2e5 + 100;
int64_t a[N];

void solve() {
  int n;
  int64_t x, y;
  cin >> n >> x >> y;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int64_t S = 0;
  for (int i = 0; i < n; i++) {
    S += a[i];
  }

  sort(a, a + n);

  int64_t ans = 0;

  for (int i = 0; i < n; i++) {
    auto v = a[i];

    // S - v - p >= x
    // S - v - p <= y

    // p >= S - v - y
    // p <= S - v - x

    auto l = lower_bound(a, a + i, S - v - y);
    auto r = upper_bound(a, a + i, S - v - x);

    ans += max(int(r - l), 0);
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
