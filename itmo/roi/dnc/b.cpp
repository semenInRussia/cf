// semenInRussia 2025
// https://cses.fi/problemset/task/2194
#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iostream>
#pragma GCC target("avx2")

using namespace std;

using pii = pair<int, int>;

int64_t dist(pii a, pii b) {
  auto x = a.first - b.first;
  auto y = a.second - b.second;
  return 1ll * x * x + 1ll * y * y;
}

const int N = 2e5 + 1000;
pii p[N], t[N];
int64_t ans = 0;
pii p1, p2;

void upd_min(pii a, pii b) {
  auto d = dist(a, b);
  if (d < ans) {
    ans = d;
    p1 = a;
    p2 = b;
  }
}

inline bool cmp(pii a, pii b) { return a.second < b.second; }

int64_t sqr(int x) { return 1ll * x * x; }

void solve(int l, int r) {
  if (r - l <= 5) {
    sort(p + l, p + r, cmp);
    for (int i = l; i < r; i++) {
      for (int j = i + 1; j < r; j++) {
        upd_min(p[i], p[j]);
      }
    }
    return;
  }

  int m = (l + r) / 2;
  int mid = p[m].first;
  solve(l, m);
  solve(m, r);

  merge(p + l, p + m, p + m, p + r, t, cmp);
  copy(t, t + r - l, p + l);

  int k = 0;
  for (int i = l; i < r; i++) {
    if (sqr(p[i].first - mid) <= ans) {
      t[k++] = p[i];
    }
  }
  for (int i = 0; i < k; i++) {
    for (int j = i + 1; j < k && j - i < 20; j++) {
      upd_min(t[i], t[j]);
    }
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  cout.tie(nullptr);
#ifndef home
  freopen("rendezvous.in", "r", stdin);
  freopen("rendezvous.out", "w", stdout);
#endif
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> p[i].first >> p[i].second;
  }
  sort(p, p + n);
  p1 = p[0];
  p2 = p[1];
  ans = dist(p1, p2);
  solve(0, n);

  // cout << ans;
  cout << p1.first << " " << p1.second << "\n";
  cout << p2.first << " " << p2.second << "\n";
}
