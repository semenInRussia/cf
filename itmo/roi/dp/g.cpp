// semenInRussia 2025
#include <cassert>
#include <cstdint>
#include <iostream>

using namespace std;

int n, r;

const int N = 6000;
int dp[N];

int fac[N][N];

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
#ifndef home
  freopen("twothree.in", "r", stdin);
  freopen("twothree.out", "w", stdout);
#endif
  cin >> n >> r;

  for (int i = 0; i <= n + 1; i++) {
    fac[0][i] = fac[i][0] = 1;
  }

  for (int i = 1; i <= n + 1; i++) {
    for (int j = 1; j <= n + 1; j++) {
      fac[i][j] = (fac[i - 1][j] + fac[i][j - 1]) % r;
    }
  }

  dp[2] = 1;
  dp[3] = 1;
  for (int l = 4; l <= n; l++) {
    dp[l] = 0;
    for (int a = 0; a * 2 <= l; a++) {
      int b = l - 2 * a;
      if (b % 3 || b < 0) {
        continue;
      }
      b /= 3;
      assert(a + b < l);
      dp[l] = (1ll * dp[a + b] * fac[a][b] + dp[l]) % r;
    }
  }

  for (int i = 0; i < 15; i++) {
    cerr << i << ": " << dp[i] << "\n";
  }

  dp[1] = 1;

  cout << dp[n];
}
