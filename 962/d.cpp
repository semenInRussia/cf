// semenInRussia 2024
#include <iostream>
using namespace std;

void solve() {
  int n, x;
  cin >> n >> x;
  using ll = long long;
  ll D = 0;
  while ((3 * D <= x) && ((1ll * D * D) * 3 <= n))
    D++;
  D--;
  ll ans = D * D * D;
  for (ll a = D + 1; a <= x && a <= n; a++) {
    // a + b + c <= x
    // ab + bc + ac <= n
    for (ll b = 1; a + b + b <= x && a * b + b * b + a * b <= n && b < a; b++) {
      for (ll c = b; a + b + c <= x && a * b + b * c + a * c <= n; c++) {
        if (b == c && a == c)
          ans += 1;
        else if (b == c || a == c || a == b)
          ans += 3;
        else
          ans += 1;
      }
    }
  }
  cout << ans << '\n';
}

int main() {
  int T;
  cin >> T;
  while (T--)
    solve();
}
