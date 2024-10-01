// semenInRussia 2024
// http..
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

void solve() {
  int n, k;
  cin >> n >> k;
  if (k == 1) {
    cout << n << '\n';
    return;
  }
  int ans = 0;
  while (n) {
    ans += n % k;
    n /= k;
  }

  cout << ans << '\n';
}

int main() {

  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
