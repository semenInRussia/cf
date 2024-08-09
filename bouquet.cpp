// semenInRussia 2024
// https://codeforces.com/problemset/problem/1995/B2
#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;
const int N = 3e5;
pair<ll, ll> p[N]; // {a, c}
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
    p[n] = {-1, -1};

    ll ans = 0;
    for (int i = 0; i < n; i++) {
      auto [a1, c1] = p[i];
      auto [a2, c2] = p[i + 1];

      if (a2 != a1 + 1) {
        ll cur = min(c1, m / a1) * a1;
        ans = max(ans, cur);
        continue;
      }

      ll x = min(c1, m / a1);
      ll y = min(c2, (m - x * a1) / a2);
      ll add = min({x, c2 - y, (m - x * a1) % a2});
      ll cur = (x * a1) + (y * a2) + add;
      ans = max(cur, ans);
    }
    cout << ans << '\n';
  }
}
