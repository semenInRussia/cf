// semenInRussia 2024
// https://codeforces.com/problemset/problem/1995/B2
#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 3e5;
pii p[N]; // {a, c}
const int C = 5000;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    ll m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
      cin >> p[i].first;
    for (int i = 0; i < n; i++)
      cin >> p[i].second;

    sort(p, p + n);

    ll ans = 0;
    for (int i = 1; i < n; i++) {
      auto [a1, c1] = p[i - 1];
      auto [a2, c2] = p[i];

      if (a2 - a1 != 1)
        a1 = 0, c1 = 0;

      if (a1 > a2) {
        swap(a1, a2);
        swap(c1, c2);
      }

      ll g = min((ll)c2, m / a2);
      for (ll i = 0; i <= g; i++) {
        ll cur = i * a2;
        cur += 1ll * min((m - i * a2) / a1, 1ll * c1) * a1;
        ans = max(ans, cur);
      }
    }
    cout << ans << '\n';
  }
}
