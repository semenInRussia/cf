// semenInRussia 2024
#include <iostream>
#include <map>
using namespace std;
using ll = long long;

const int N = 2e5;
int a[N];

void solve() {
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  map<ll, ll> cnt;
  for (int i = 0; i + 1 < n; i++) {
    ll f = (i + 1) * 1ll * (n - i - 1);
    ll c = a[i + 1] - a[i] - 1;
    c = max(0ll, c);
    cnt[f] += c;
  }
  // check every point
  for (int i = 0; i < n; i++) {
    ll f = 1ll * (i + 1) * (n - i - 1);
    f += i;
    cnt[f]++;
  }

  for (int i = 0; i < q; i++) {
    ll k;
    cin >> k;
    cout << cnt[k] << ' ';
  }
  cout << '\n';
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
