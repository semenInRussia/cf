// semenInRussia 2025
#ifndef home
#pragma GCC optimize("O3,unroll-loops")
#endif
#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <vector>
#ifndef home
#pragma GCC target("avx2")
#endif

using namespace std;

signed main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int m, n, k;
  cin >> m >> n >> k;

  vector<pair<int, int>> t(k);

  for (auto &lr : t) {
    cin >> lr.first >> lr.second;
  }
  sort(t.begin(), t.end(), [](auto a, auto b) {
    return a.first < b.first || (a.first == b.first && a.second > b.second);
  });

  int mx = -1;
  int pos = 0;

  for (int i = 0; i < k; i++) {
    if (t[i].second <= mx) {
      // delete
      continue;
    }
    mx = max(mx, t[i].second);
    t[pos++] = t[i];
  }

  t.resize(pos);
  k = pos;
  sort(t.begin(), t.end());

  vector<vector<int>> h(m, vector<int>(2 * n));

  for (auto &row : h) {
    for (int &x : row) {
      cin >> x;
    }

    sort(row.begin(), row.end());
  }

  vector<int> b(2 * m);
  vector<int64_t> pref(2 * m + 1);

  auto check = [&](pair<int, int> bounds) {
    auto [l, r] = bounds;
    int L = lower_bound(b.begin(), b.end(), l) - b.begin();
    int R = upper_bound(b.begin(), b.end(), r) - b.begin();

    int64_t ans = -1ll * r * (2 * m - R) + 1ll * l * L - pref[L] +
                  (pref.back() - pref[R]);
    return ans;
  };

  int64_t ans = 0;

  auto f = [&](auto f, int l, int r, int st, int en) -> void {
    if (r - l <= 0) {
      return;
    }
    int i = (l + r) / 2;
    for (int j = 0; j < m; j++) {
      b[2 * j] = h[j][2 * i];
      b[2 * j + 1] = h[j][2 * i + 1];
    }
    sort(b.begin(), b.end());
    for (int j = 0; j < 2 * m; j++) {
      pref[j + 1] = pref[j] + b[j];
    }
    int cur = st;
    auto mn = check(t[st]);
    for (int l = st + 1; l < en; l++) {
      auto op = check(t[l]);
      if (op < mn) {
        cur = l;
        mn = op;
      }
    }
    ans += mn;

    f(f, l, i, st, cur + 1);
    f(f, i + 1, r, cur, en);
  };

  f(f, 0, n, 0, k);

  cout << ans;
}
