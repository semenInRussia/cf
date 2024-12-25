// semenInRussia 2024
// https://codeforces.com/contest/2051/problem/E
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <set>
using namespace std;

const int N = 1e6;
int a[N], b[N];

const int inf = 2e9 + 1000;

pair<int, int> p[N];

int op[N];

void solve() {
  int n, k;
  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }

  for (int i = 0; i < n; i++) {
    p[i] = {a[i], b[i]};
  }

  int m = 0;

  for (int i = 0; i < n; i++) {
    op[m++] = a[i];
  }

  for (int i = 0; i < n; i++) {
    op[m++] = b[i];
  }

  int64_t ans = 0;

  sort(p, p + n, [](auto x, auto y) { return x.second > y.second; });
  sort(op, op + m);

  int j = 0; // j in p
  int cnt = 0;
  int bad = 0;

  multiset<pair<int, int>> s;
  multiset<pair<int, int>> s2;

  for (int i = 0; i < n; i++) {
    auto [l, r] = p[i];

    s2.insert(p[i]);
    s.insert({r, l});

    cnt++;
    j++;
  }

  for (int i = 0; i < m; i++) {
    int x = op[i];

    while (!s.empty()) {
      auto [r, l] = *s.begin();
      if (r >= x) {
        break;
      }
      if (x > l) {
        bad--;
      }
      cnt--;
      s.erase(s.begin());
      auto it = s2.find({l, r});
      if (it != s2.end()) {
        s2.erase(it);
      }
    }

    while (!s2.empty()) {
      auto [l, r] = *s2.begin();
      if (l >= x) {
        break;
      }

      bad++;
      s2.erase(s2.begin());
    }

    if (bad <= k) {
      auto op = 1ll * x * cnt;
      ans = max(op, ans);
    }
  }

  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
