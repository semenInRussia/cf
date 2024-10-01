// semenInRussia 2024
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
using ll = long long;

const int N = 2e5;
ll a[N];

void solve() {
  int n;
  ll k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  ll mcnt = *max_element(a, a + n);
  ll s = accumulate(a, a + n, 0ll);
  ll ans = -1;
  for (int x = 1; x <= n; x++) {
    // x - is answer (length of decks)
    // maximum x = n
    //
    // check that x can be
    ll cnt = max(mcnt, (s + x - 1) / x);
    if (s + k >= cnt * x) {
      ans = x;
    }
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
