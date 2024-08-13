// semenInRussia 2024
// https://cses.fi/problemset/task/1639
#include <iostream>
using namespace std;

const int N = 5005, inf = 1e9 + 5;
int f[N][N];

int main() {
  string a, b;
  cin >> a >> b;
  int n = int(a.size());
  for (int i = 1; i <= n; i++) {
    f[i][0] = i;
  }

  int m = int(b.size());
  for (int j = 1; j <= m; j++) {
    f[0][j] = j;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int &ans = f[i + 1][j + 1];
      ans = inf;
      if (a[i] == b[j])
        ans = f[i][j];

      ans = min(ans, 1 + f[i][j]);
      ans = min(ans, 1 + f[i][j + 1]);
      ans = min(ans, 1 + f[i + 1][j]);
    }
  }

  cout << f[n][m];
}
