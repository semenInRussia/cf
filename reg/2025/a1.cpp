// semenInRussia 2025
#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iostream>
using namespace std;

void solve() {
  int n, m, k;
  cin >> n >> m >> k;

  if (m > n) {
    swap(n, m);
  }

  int x = (m - 1) / k;

  int i = k * x + 1;
  int j = k * x + 1;

  int ans = x;

  int v = m - i;
  if (v > 0) {
    ans++;
    j += v;
    i += v;
  }
  if (n - i > 0) {
    ans += (n - i + k - 1) / k;
  }
  cout << ans << "\n";
}

int main() {
  int tt = 1;
#ifdef home
  cin >> tt;
#endif
  while (tt--) {
    solve();
    cout << "\n";
  }
}
