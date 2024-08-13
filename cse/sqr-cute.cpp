// semenInRussia 2024
// https://cses.fi/problemset/task/1744
#include <iostream>
using namespace std;

const int N = 503, inf = 1e9 + 5;
int f[N][N];

int main() {
  int a, b;
  cin >> a >> b;
  for (int i = 1; i <= a; i++) {
    for (int j = 1; j <= b; j++) {
      int &ans = f[i][j];
      if (i == j) {
        ans = 1;
        continue;
      }
      ans = +inf;
      for (int m = 1; m < i; m++) {
        ans = min(ans, f[i - m][j] + f[m][j]);
      }
      for (int m = 1; m < j; m++) {
        ans = min(ans, f[i][j - m] + f[i][m]);
      }
    }
  }
  cout << f[a][b] - 1;
}
