// semenInRussia 2024
#include <algorithm>
#include <iostream>
using namespace std;

const int N = 110, inf = 1e9;
int a[N][N], f[N][N];

int main() {
  int n;
  cin >> n;
  for (int tour = 0; tour < n; tour++) {
    int i = tour, j = 0;
    while (i >= 0) {
      cin >> a[i][j];
      f[i][j] = -inf;
      i--, j++;
    }
  }
  f[0][0] = a[0][0];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - i; j++) {
      if (i)
        f[i][j] = max(f[i][j], a[i][j] + f[i - 1][j]);
      if (j)
        f[i][j] = max(f[i][j], a[i][j] + f[i][j - 1]);
    }
  }
  int ans = -inf;
  for (int i = 0; i < n; i++)
    ans = max(ans, f[i][n - i - 1]);
  cout << ans << '\n';
}
