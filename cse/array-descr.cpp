// semenInRussia 2024
// https://cses.fi/problemset/task/1746
#include <iostream>
using namespace std;

const int M = 101, N = 1e5 + 5, mod = 1e9 + 7;
int f[N][M], x[N];

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }

  // f[i + 1][j] - is amount of RIGHT sequences, ending with i digit=j
  // compute f[0][0]
  if (x[0]) {
    f[0][x[0]] = 1;
  } else {
    for (int j = 1; j <= m; j++) {
      f[0][j] = 1;
    }
  }

  for (int i = 1; i < n; i++) {
    if (x[i]) {
      int cur = 0; // sum of f[i][..]
      for (int j : {x[i] - 1, x[i], x[i] + 1}) {
        if (j <= 0 || j > m)
          continue;
        cur += f[i - 1][j];
        cur -= mod * (cur >= mod);
      }
      f[i][x[i]] = cur;
      continue;
    }

    for (int j = 1; j <= m; j++) {
      // compute f[i + 1][j]
      int cur = 0;
      for (int y : {j - 1, j, j + 1}) {
        if (y <= 0 || y > m)
          continue;
        cur += f[i - 1][y];
        cur -= mod * (cur >= mod);
      }
      f[i][j] = cur;
    }
  }

  int ans = 0;
  for (int j = 1; j <= m; j++) {
    ans += f[n - 1][j];
    ans -= mod * (ans >= mod);
  }
  cout << ans;
}
