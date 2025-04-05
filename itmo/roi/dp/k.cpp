// semenInRussia 2025
#ifndef home
#pragma GCC optimize("O3,unroll-loops")
#endif
#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>
#ifndef home
#pragma GCC target("avx2")
#endif
#include <vector>

using namespace std;

const int N = 100'005;

const int inf = 1e9;

template <typename T> T &setmax(T &v, T op) { return v = max(v, op); }

int cnt(int a, int b, int c) {
  int f[4] = {0, 0, 0, 0};
  for (int x : {a, b, c}) {
    f[x] = 1;
  }
  return f[1] + f[2] + f[3];
}

int dp[N][4][4][4][4];

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
#ifndef home
  freopen("miners.in", "r", stdin);
  freopen("miners.out", "w", stdout);
#endif
  int n;
  cin >> n;
  string s;
  cin >> s;

  for (int i = 0; i <= n; i++) {
    for (int a = 0; a < 5; a++) {
      for (int b = 0; b < 5; b++) {
        for (int c = 0; c < 5; c++) {
          for (int d = 0; d < 5; d++) {
            dp[i][a][b][c][d] = -inf;
          }
        }
      }
    }
  }

  dp[0][0][0][0][0] = 0;

  char h[5] = " BMF";

  for (int i = 0; i < n; i++) {
    int g = find(h, h + 5, s[i]) - h;
    for (int a = 0; a < 4; a++) {
      for (int b = 0; b < 4; b++) {
        for (int c = 0; c < 4; c++) {
          for (int d = 0; d < 4; d++) {
            int cur = dp[i][a][b][c][d];
            setmax(dp[i + 1][g][a][c][d], cur + cnt(g, a, b));
            setmax(dp[i + 1][a][b][g][c], cur + cnt(g, c, d));
          }
        }
      }
    }
  }

  int ans = 0;

  for (int a = 0; a < 5; a++) {
    for (int b = 0; b < 5; b++) {
      for (int c = 0; c < 5; c++) {
        for (int d = 0; d < 5; d++) {
          setmax(ans, dp[n][a][b][c][d]);
        }
      }
    }
  }

  cout << ans;
}
