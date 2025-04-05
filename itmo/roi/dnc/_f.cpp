// semenInRussia 2025
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  // #ifndef home
  //   freopen("maxxor.in", "r", stdin);
  //   freopen("maxxor.out", "w", stdout);
  // #endif
  int n;
  cin >> n;
  vector<int> a(n), p(n + 1);
  for (int &x : a) {
    cin >> x;
  }
  for (int i = 0; i < n; i++) {
    p[i + 1] = p[i] ^ a[i];
  }

  int64_t ans = 0;

  for (int l = 0; l < n; l++) {
    int mx = a[l];
    for (int r = l + 1; r <= n; r++) {
      mx = max(mx, a[r - 1]);
      ans = max(ans, 1ll * mx * (p[r] ^ p[l]));
    }
  }

  cout << ans;
}
