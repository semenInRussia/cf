// semenInRussia 2024
#include <cstdint>
#include <iostream>
#include <set>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,fma,bmi2,tune=native")

const int N = 2005;
int a[N][N], b[N][N];

int64_t f1[N][N];
int64_t f2[N][N];

const int64_t inf = 1e18 + 100;

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> b[i][j];
    }
  }

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      f1[i][j] = f2[i][j] = +inf;
    }
  }

  f1[n - 1][n - 1] = a[n - 1][n - 1];

  for (int i = n - 1; i >= 0; i--) {
    for (int j = n - 1 - (i == n - 1); j >= 0; j--) {
      f1[i][j] = min(f1[i + 1][j], f1[i][j + 1]) + a[i][j];
    }
  }

  f2[1][1] = b[0][0];

  for (int i = 0; i < n; i++) {
    for (int j = i == 0; j < n; j++) {
      f2[i + 1][j + 1] = min(f2[i][j + 1], f2[i + 1][j]) + b[i][j];
    }
  }

  int64_t B = +inf;
  int64_t ans = +inf;

  for (int i = n - 1; i >= 0; i--) {
    B = min(B, f2[i + 1][n]);

    for (int j = 1; j < n; j++) {
      ans = min(ans, f1[i][j] + B);
    }
  }

  B = +inf;

  for (int j = n - 1; j >= 0; j--) {
    B = min(B, f2[n][j + 1]);

    for (int i = 1; i < n; i++) {
      ans = min(ans, B + f1[i][j]);
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = i == 0; j < n; j++) {
      ans = min(ans, f1[i][j] + f2[n][n]);
    }
  }

  ans = min(ans, f2[n][n]);

  cout << ans;
}
