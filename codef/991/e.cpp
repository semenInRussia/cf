// semenInRussia 2024
#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,fma,bmi2,tune=native")

#define isz(x) int(x.size())

const int inf = 1e9 + 5;

void solve() {
  string a, b, c;
  cin >> a >> b >> c;

  // f[i][j] - minimum errors that a[0..i) located on c[0..j]
  // answer = f[isz(a)][isz(c)]

  vector<vector<int>> f(isz(a) + 3, vector<int>(isz(b) + 3, +inf));

  f[0][0] = 0;

  for (int i = 0; i <= isz(a); i++) {
    for (int j = 0; j <= isz(b); j++) {
      int ch = c[i + j - 1];
      auto &ans = f[i][j];
      if (i > 0) {
        ans = min(ans, f[i - 1][j] + (ch != a[i - 1]));
      }
      if (j > 0) {
        ans = min(ans, f[i][j - 1] + (ch != b[j - 1]));
      }
    }
  }

  cout << f[isz(a)][isz(b)] << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
