// semenInRussia 2024
// https://codeforces.com/contest/2049/problem/D
#include <cstdint>
#include <iostream>
using namespace std;

const int N = 210;
int a[N][N];
int64_t f[N][N][N];
int64_t mn[N][N];

const int64_t inf = 1e18 + 1000;

void setmin(int64_t &v, int64_t op) { v = min(v, op); }

void solve() {
  int n, m;
  int64_t x;
  cin >> n >> m >> x;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }

  for (int i = 0; i <= n; i++) {
    for (int j = i == 0; j < m; j++) {
      mn[i][j] = +inf;
      for (int k = 0; k < m; k++) {
        f[i][j][k] = +inf;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < m; k++) {
        auto &ans = f[i + 1][j][k];

        setmin(ans, a[i][(j + k) % m] + x * k + mn[i][j]); // up

        if (j > 0) { // left
          setmin(ans, f[i + 1][j - 1][k] + a[i][(j + k) % m]);
        }

        setmin(mn[i + 1][j], ans);
      }
    }
  }

  cout << mn[n][m - 1] << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
