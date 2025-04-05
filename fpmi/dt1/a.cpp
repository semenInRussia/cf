// semenInRussia 2025
#pragma GCC optimize("Ofast,unroll-loops")

#include <cassert>
#include <iostream>
#include <string.h>
#include <vector>

#pragma GCC target("avx2")

using namespace std;

const int inf = 1e9 + 10;

const int N = 1 << 18;

struct tree {
  int t[2 * N], lazy[2 * N];

  int sz = 1;

  void resize(int n) {
    while (sz < n) {
      sz <<= 1;
    }
    for (int i = 0; i < 2 * sz; i++) {
      t[i] = lazy[i] = 0;
    }
  }

  void apply(int x, int v) {
    t[x] += v;
    lazy[x] += v;
  }

  void push(int x) {
    if (lazy[x]) {
      int v = lazy[x];
      apply(2 * x + 1, v);
      apply(2 * x + 2, v);
      lazy[x] = 0;
    }
  }

  int getmin(int ql, int qr, int x, int l, int r) {
    if (ql <= l && r <= qr) {
      return t[x];
    }

    if (ql >= r || qr <= l) {
      return +inf;
    }

    int m = (l + r) / 2;
    push(x);
    return min(getmin(ql, qr, 2 * x + 1, l, m),
               getmin(ql, qr, 2 * x + 2, m, r));
  }

  void inc(int ql, int qr, int v, int x, int l, int r) {
    if (ql <= l && r <= qr) {
      apply(x, v);
      return;
    }

    if (ql >= r || qr <= l) {
      return;
    }

    int m = (l + r) / 2;
    push(x);
    inc(ql, qr, v, 2 * x + 1, l, m);
    inc(ql, qr, v, 2 * x + 2, m, r);
    t[x] = min(t[2 * x + 1], t[2 * x + 2]);
  }

  int getmin(int ql, int qr) { return getmin(ql, qr, 0, 0, sz); }

  void inc(int ql, int qr, int v) { return inc(ql, qr, v, 0, 0, sz); }

  void setmin(int j, int v) {
    int cur = getmin(j, j + 1);
    if (v < cur) {
      inc(j, j + 1, -cur + v);
    }
  }
};

tree f0, f1;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int tt;
  cin >> tt;

  while (tt--) {
    int n;
    cin >> n;

    f0.resize(n + 1);
    f1.resize(n + 1);

    f0.inc(1, n + 1, +inf);

    for (int i = 0; i < n; i++) {
      int ai;
      cin >> ai;

      // int f0a = f0.getmin(ai, ai + 1);
      // int f1a = f1.getmin(ai, ai + 1);
      int f0a = f0.getmin(ai, ai + 1);
      int f1a = f1.getmin(ai, ai + 1);
      int v = f0.t[0];

      f0.apply(0, +1);
      f1.apply(0, +1);

      // int old = f0.getmin(ai, ai + 1);
      f0.setmin(ai, f1a);

      // old = f1.getmin(ai, ai + 1);
      f1.setmin(ai, min(v, f0a));
    }

    int ans = f0.t[0];
    cout << ans << "\n";
  }
}
