// semenInRussia 2024
#include <cstdint>
#include <iostream>

using namespace std;

const int N = 1550;
int a[N][N];

int64_t f[N][N], g[N][N];

int64_t suf[N];

const int64_t inf = 1e18 + 5;

// f[N][N] - maximum way of mario from (i - 1, j - 1) to (n, n)
// g[N][N] - maximum way of mario from (0, 0) to (i, j)

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      f[n][j] = f[i][m] = -inf;
    }
  }

  f[n - 1][m - 1] = a[n - 1][m - 1];

  for (int i = n - 1; i >= 0; i--) {
    for (int j = m - 1 - (i == n - 1); j >= 0; j--) {
      f[i][j] = max(f[i + 1][j], f[i][j + 1]) + a[i][j];
    }
  }

  g[1][1] = a[0][0];

  for (int i = 0; i < n; i++) {
    for (int j = i == 0; j < m; j++) {
      g[i + 1][j + 1] = max(g[i + 1][j], g[i][j + 1]) + a[i][j];
    }
  }

  int64_t ans = +inf;

  for (int i = 0; i < n; i++) {
    int64_t pref = 0;

    for (int j = 0; j < m; j++) {
      auto op = max(suf[j], pref);

      pref = max(pref, g[i + 1][j + 1] + f[i + 1][j]);

      if ((i + j == 0) || (i == n - 1 && j == m - 1)) {
        continue;
      }

      ans = min(ans, op);
    }

    for (int j = m - 1; j - 1 >= 0; j--) {
      suf[j - 1] = max(suf[j], g[i + 1][j + 1] + f[i + 1][j]);
    }
  }

  cout << ans;
}
