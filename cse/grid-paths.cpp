// https://cses.fi/problemset/task/1638
// semenInRussia 2024
// https://cses.fi/problemset/task/1637
#include <iostream>
using namespace std;

const int N = 1e3 + 10, mod = 1e9 + 7;
int f[N][N];
string t[N];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }
  f[0][1] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      f[i + 1][j + 1] = (f[i + 1][j] + f[i][j + 1]) % mod;
      if (t[i][j] == '*')
        f[i + 1][j + 1] = 0;
    }
  }
  cout << f[n][n];
}
