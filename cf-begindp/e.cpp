// semenInRussia 2024
#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

const int N = 110, inf = 1e9;
int a[N][N], f[N][N];

int main() {
  freopen("slalom.out", "w", stdout);
  freopen("slalom.in", "r", stdin);
  int n;
  cin >> n;
  // let's slalom is square, but without half
  // the size is NxN
  //
  // 1
  // 4 3
  // 5 6 7
  // 8 9 0 9
  //
  //
  // 8
  // 5 9
  // 3 6 0
  // 1 4 7 9
  for (int tour = 0; tour < n; tour++) {
    // height i:
    int i = n - tour - 1;
    int j = 0;
    while (i < n) {
      cin >> a[i][j];
      i++, j++;
    }
  }

  // find f[i][i]
  // can move only right, up
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= i; j++)
      f[i][j] = -inf;
  f[n - 1][0] = a[n - 1][0];
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j <= i; j++) {
      if (i + 1 < n)
        f[i][j] = max(f[i][j], a[i][j] + f[i + 1][j]);
      if (j)
        f[i][j] = max(f[i][j], a[i][j] + f[i][j - 1]);
    }
  }
  int ans = -inf;
  for (int i = 0; i < n; i++)
    ans = max(ans, f[i][i]);
  cout << ans << '\n';
}
