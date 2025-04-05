// semenInRussia 2025
#include <cstdint>
#include <iomanip>
#include <iostream>

using namespace std;

using ld = long double;

const ld inf = 1e18;

const int N = 110;
ld dp[N][N];
int a[N];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < n; i++) {
    dp[i][i + 1] = a[i];
  }

  for (int len = 2; len <= n; len++) {
    for (int i = 0; i + len <= n; i++) {
      int j = i + len;
      dp[i][j] = 0;
      for (int k = i + 1; k < j; k++) {
        dp[i][j] = max(dp[i][j], (dp[i][k] + dp[k][j]) * 0.5L);
      }
    }
  }

  cout << setprecision(6) << fixed;
  cout << dp[0][n];
}
