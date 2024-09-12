// SadMachine 2024
#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
#define int i64
constexpr int INF = 1e18 + 7;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int m, x;
    cin >> m >> x;
    vector<int> c(m), h(m);
    int s = 0;
    for (int i = 0; i < m; i++) {
      cin >> c[i] >> h[i];
      s += h[i];
    }
    vector<int> dp(s + 1, -INF);
    dp[0] = 0;
    for (int i = 0; i < m; i++) {
      for (int j = s; j >= h[i]; j--) {
        if (dp[j - h[i]] - c[i] >= 0)
          dp[j] = max(dp[j], dp[j - h[i]] - c[i]);
      }
      for (int j = 0; j <= s; j++) {
        if (dp[j] >= 0)
          dp[j] += x;
      }
    }
    int ans = 0;
    for (int j = 0; j <= s; j++) {
      if (dp[j] >= 0)
        ans = j;
    }
    cout << ans << "\n";
  }
}
