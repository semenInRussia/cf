// semenInRussia 2024
using namespace std;
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using ll = long long;
using pii = pair<int, int>;

int main() {
  vector<pii> s(3);
  for (int i = 0; i < 3; i++) {
    cin >> s[i].first >> s[i].second;
    if (s[i].first < s[i].second) {
      swap(s[i].first, s[i].second);
    }
  }

  sort(s.begin(), s.end());

  // 3 in row
  ll ans = LLONG_MAX;
  for (int z = 0; z < 8; z++) {
    vector<pii> d = s;
    int r1 = z & 1;
    int r2 = (z >> 1) & 1;
    int r3 = (z >> 2) & 1;
    if (r1) {
      swap(d[0].first, d[0].second);
    }
    if (r2) {
      swap(d[1].first, d[1].second);
    }
    if (r3) {
      swap(d[2].first, d[2].second);
    }

    // 3 in row
    ll op = max(d[0].first, max(d[1].first, d[2].first));
    op *= (d[0].second + d[1].second + d[2].second);
    ans = min(op, ans);

    // 2 in row, 1 in other
    // all orders
    for (int i = 0; i < 3; i++) {
      vector<pii> c = d;
      c.erase(c.begin() + i);
      int a = max(d[i].first, c[0].first + c[1].first);
      int b = d[i].second + max(c[0].second, c[1].second);
      ans = min(ans, 1ll * a * b);
    }
  }

  cout << ans;
}
