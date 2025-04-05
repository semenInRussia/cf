// semenInRussia 2025
#include <cstdint>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n;
  cin >> n;

  map<int, ll> cnt;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    ll v = 1;

    while (x % 2 == 0) {
      v *= 2;
      x /= 2;
    }

    cnt[x] += v;
  }

  ll ans = 0;

  for (auto [_x, c] : cnt) {
    auto x = _x;
    ans = max(ans, 1ll * x);
    ll op = 1ll * x * (1ll << __lg(c));
    ans = max(op, ans);
  }

  cout << ans << "\n";
}
