// semenInRussia 2024
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int N = 3e5, inf = 1e9;
int a[N];

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  vector<ll> odd, ev;
  for (int i = 0; i < n; i++) {
    if (a[i] & 1)
      odd.push_back(a[i]);
    else
      ev.push_back(a[i]);
  }

  if (ev.empty() || odd.empty()) {
    cout << "0\n";
    return;
  }

  sort(ev.begin(), ev.end());
  sort(odd.begin(), odd.end());

  // we can:
  //
  // choose
  // - ans += 2, mx += x * 2
  // - ans += 1, mx += x

  int ans = 0;
  ll mx = odd.back();
  ll A = 1e9 + 7;

  int i = 0;
  int evs = int(ev.size());
  while (i < evs && mx > ev[i]) {
    mx += ev[i];
    mx = min(mx, A);
    ans++;
    i++;
  }

  int res = +inf;
  for (int z : {1, 2}) {
    int _ans = ans;
    ll _mx = mx;

    // two variants
    int j = i;
    while (j < evs) {
      ll x = ev[j];
      if (mx > x) {
        ans++;
        mx += x;
        mx = min(mx, A);
      } else {
        ans += 2;
        mx += 1ll * x * 2;
        mx = min(mx, A);
      }
      j++;
    }

    res = min(res, ans);
    swap(_ans, ans);
    swap(_mx, mx);

    ans++;
    mx += 1ll * ev.back();
  }

  cout << res << '\n';
}

int main() {
  int tt;
  cin >> tt;
  while (tt--)
    solve();
}
