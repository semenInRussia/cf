// semenInRussia 2025
#include <cstdint>
#include <iostream>

using namespace std;

void solve() {
  int n, m, t;
  cin >> n >> m >> t;

  int64_t ans = 0;

  // cerr << n << " " << m << " " << t << "\n";
  n++, m++;

  for (int a = 2; a <= n; a++) {
    int v = (t + a + 2 * a - 2) / (2 * a - 1);
    v = max(2, v);
    ans += max(0, min(m - 2 + 1, m - v + 1));
  }

  // cerr << "\n--";

  cout << ans;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int tt = 1;
#ifdef home
  cin >> tt;
#endif

  while (tt--) {
    solve();
    cout << "\n";
  }
}
