// semenInRussia 2024
#include <cstdint>
#include <iostream>
using namespace std;

void solve() {
  int n, a, b, c;
  cin >> n >> a >> b >> c;

  int ans =
      min(a, n) + min(b, n) + max(0, min(c, 2 * n - min(a, n) - min(b, n)));
  cout << ans << "\n";
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
