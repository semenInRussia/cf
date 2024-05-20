// 2024 semenInRussia
#include <iostream>
#include <map>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int maxn = 2e5 + 100;
int a[maxn];

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  ll ans = 0;
  map<pii, ll> xy, yz, xz;
  map<ll, ll> xyz;
  for (int i = 0; i + 2 < n; i++) {
    int x = a[i], y = a[i + 1], z = a[i + 2];
    ans += xy[{x, y}];
    ans += xz[{x, z}];
    ans += yz[{y, z}];
    ll h = (ll(x) << 20ll) + (ll(y) << 40ll) + ll(z);
    if (xyz.count(h))
      ans -= 3 * xyz[h];
    xyz[h] = xyz.count(h) ? xyz[h] + 1ll : 1;
    xy[{x, y}] = xy.count({x, y}) ? xy[{x, y}] + 1ll : 1;
    yz[{y, z}] = yz.count({y, z}) ? yz[{y, z}] + 1ll : 1;
    xz[{x, z}] = xz.count({x, z}) ? xz[{x, z}] + 1ll : 1;
  }
  cout << ans << '\n';
}

int main() {
  int tt;
  cin >> tt;
  while (tt--)
    solve();
}
