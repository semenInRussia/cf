// semenInRussia 2025
#include <algorithm>
#include <cstdint>
#include <iostream>

using namespace std;

const int N = 305;
int a[N][N];
int suf[N];

void solve() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }

    // count ones at suffix for i'th row
    int x = 0;
    while (x < n && a[i][n - x - 1] == 1) {
      x++;
    }

    suf[i] = x;
  }

  sort(suf, suf + n);

  int ans = 0;
  for (int j = 0; j < n; j++) {
    int x = suf[j];
    if (x >= ans) {
      ans++;
    }
  }

  cout << ans << "\n";
}

int main() {
  int tt = 1;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
