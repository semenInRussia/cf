// semenInRussia 2024
// https://codeforces.com/problemset/problem/2046/C
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#ifdef ONLINE_JUDGE
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,fma,bmi2,tune=native")
#endif

#define isz(x) int(x.size())

const int N = 3e5 + 100;

int b[N];
int u;

int id(int x) { return lower_bound(b, b + u, x) - b; }

struct fenw {
  int t[N];
  int n;
  int s;

  void resize(int k) {
    n = k;
    for (int i = 0; i <= n; i++) {
      t[i] = 0;
    }
    s = 0;
  }

  int sum(int j) {
    int ans = 0;
    for (; j > 0; j -= j & -j) {
      ans += t[j];
    }
    return ans;
  }

  int sum(int i, int j) { return sum(j) - sum(i); }

  void add(int j, int v) {
    s += v;
    for (j++; j <= n; j += j & -j) {
      t[j] += v;
    }
  }

  void fill(int x) {
    s = 0;
    for (int i = 0; i <= n; i++) {
      t[i] = 0;
    }
  }

  pair<int, int> bounds(int k) {
    int L, R;

    int l = -1;
    int r = u;

    // first j; sum(j) >= k
    bool ok = 0;
    while (r - l > 1) {
      int m = (r - l) / 2 + l;
      if (sum(m) >= k) {
        ok = 1;
        r = m;
      } else {
        l = m;
      }
    }
    L = r;

    if (!ok) {
      return {5, 0};
    }

    // last j; sum(j; n) <= k
    l = -1;
    r = u;
    while (r - l > 1) {
      int m = (r - l) / 2 + l;
      if (sum(m, n) >= k) {
        l = m;
      } else {
        r = m;
      }
    }
    R = l;

    return {b[L], b[R]};
  }
};

pair<int, int> p[N];

fenw f, g;
fenw _g;

void copy(fenw &a, fenw &b) {
  for (int i = 0; i <= a.n; i++) {
    b.t[i] = a.t[i];
  }
  b.s = a.s;
}

int idx[N];

void solve() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> p[i].first >> p[i].second;
  }

  for (int i = 0; i < n; i++) {
    b[i] = p[i].first;
  }

  for (int i = 0; i < n; i++) {
    b[i + n] = b[i] - 1;
    b[i + n + n] = b[i] + 1;
  }

  sort(b, b + 3 * n);
  u = unique(b, b + 3 * n) - b;

  f.resize(u);
  g.resize(u);
  _g.resize(u);

  // iterate horizontal line

  int l = 0;
  int r = (n / 3) + 10;

  pair<int, pair<int, int>> ans = {0, {0, 0}};

  int j = 0;

  sort(p, p + n);

  for (int i = 0; i < n; i++) {
    auto [x, y] = p[i];
    while (b[j] != x) {
      j++;
    }
    _g.add(j, +1);
  }

  sort(p, p + n, [](auto a, auto b) { return a.second < b.second; });
  reverse(p, p + n);

  for (int i = 0; i < n; i++) {
    idx[i] = id(p[i].first);
  }

  while (r - l > 1) {
    if (ans.first >= r) {
      break;
    }

    f.fill(0);
    copy(_g, g);

    int k = (r + l) / 2;
    bool ok = 0;

    for (int i = 0; i < n; i++) {
      auto [x, y] = p[i];
      int xx = idx[i];

      f.add(xx, +1);
      g.add(xx, -1);

      if (f.s < 2 * k) {
        continue;
      }
      if (g.s < 2 * k) {
        break;
      }

      if (i + 1 < n && y == p[i + 1].second) {
        continue;
      }

      auto [l1, r1] = f.bounds(k);
      if (l1 > r1) {
        continue;
      }

      auto [l2, r2] = g.bounds(k);
      ok = !(l2 > r1 || r2 < l1) && (l1 <= r1 && l2 <= r2);

      if (ok) {
        ans = max(ans, {k, {max(l1, l2), y}});
        ok = 1;
        break;
      }
    }

    if (ok) {
      l = k;
    } else {
      r = k;
    }
  }

  cout << ans.first << "\n";
  auto [x, y] = ans.second;
  cout << x << " " << y << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
