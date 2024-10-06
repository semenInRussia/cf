// semenInRussia 2024
// https://codeforces.com/contest/2021/problem/D
#include <iostream>
#include <vector>
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }

  // f[i][l][r]
  // .....
  //
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
