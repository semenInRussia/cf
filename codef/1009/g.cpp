// semenInRussia 2025
#include <cstdint>
#include <iostream>

using namespace std;

using ll = long long;
const int N = 500;
ll a[N], dp[N][N];

template <typename T> T &setmax(T &cur, T op) { return cur = max(cur, op); }

int n;

ll inner(int i, int j) {
  int d = j - i;
  if (d < 0) {
    d += n;
  }
  --d;

  if (d <= 2) {
    return 0;
  }

  return dp[(i + 1) % n][(j - 1 + n) % n];
}

void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  long long ans = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      dp[i][j] = 0;
    }
  }

  for (int i = 0; i < n; i++) {
    int j = (i + 2) % n;
    int k = (i + 1) % n;
    dp[i][j] = a[i] * a[k] * a[j];
    ans = max(ans, dp[i][j]);
  }

  for (int len = 3; len < n; len++) {
    for (int i = 0; i < n; i++) {
      int j = (i + len) % n;
      dp[i][j] = max(dp[(i + 1) % n][j], dp[i][(j - 1 + n) % n]);
      // otherwise we have edge i->j
      for (int k = (i + 1) % n; k != j; k = (k + 1) % n) {
        setmax(dp[i][j], dp[i][k] + dp[(k + 1) % n][j]);
      }
      for (int k = (i + 1) % n; k != j; k = (k + 1) % n) {
        setmax(dp[i][j], a[i] * a[j] * a[k] + inner(i, k) + inner(k, j));
      }
      ans = max(ans, dp[i][j]);
    }
  }

  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
