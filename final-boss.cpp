// semenInRussia 2024
// place for link: https://codeforces.com/contest/1985/problem/F
#include <iostream>
using namespace std;
using ll = long long;

const int maxn = 3e5;
ll a[maxn], c[maxn], h;
int n;
ll ok(ll t) {
  ll d = 0;
  for (int i = 0; i < n && d < h; i++) {
    ll v = (t / c[i]) + 1;
    if (v > (h - d) / a[i]) // guard for Overflow
      return true;
    d += v * a[i];
  }
  return d >= h;
}
void solve() {
  cin >> h >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    cin >> c[i];
  ll l = -1, r = 1e18;
  while (r > l + 1) {
    ll m = (r - l) / 2 + l;
    if (ok(m))
      r = m;
    else
      l = m;
  }
  // before it I was used 0-indexes (it's more easy to programming),
  // but answers must be 1-index
  cout << (r + 1) << '\n';
}

int main() {
  int tt;
  cin >> tt;
  while (tt--)
    solve();
}
