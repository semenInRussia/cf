// semenInRussia 2025
#include <cstdint>
#include <iostream>
#include <map>
#include <math.h>
#include <vector>

using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;

  vector<int> x(n), r(n);
  for (int &el : x) {
    cin >> el;
  }
  for (int &el : r) {
    cin >> el;
  }

  map<int, long long> mp;

  for (int i = 0; i < n; i++) {
    for (int j = x[i] - r[i]; j <= x[i] + r[i]; j++) {
      mp[j] = max(mp[j], 0ll);
      // (x[i] - j)^2 + y^2 <= r[i]^2
      // y^2 <= r[i]^2 + (x[i] - j)^2
      int64_t v = 1ll * r[i] * r[i] - 1ll * (x[i] - j) * (x[i] - j);
      if (v >= 0) {
        auto s = int64_t(sqrt(v));
        mp[j] = max(mp[j], s);
      }
    }
  }

  int64_t ans = 0;
  for (auto [j, s] : mp) {
    ans += s * 2 + 1;
  }

  cout << ans << "\n";
}

int main() {
  int tt = 1;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
