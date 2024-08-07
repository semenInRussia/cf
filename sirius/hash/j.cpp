// semenInRussia 2024
#include <cassert>
#include <iostream>
using namespace std;
using ull = unsigned long long;

const int N = 1 << 19, C = 1e5 + 7, mod = 1e9 + 123;
int p[N];
ull tp[N];

template <typename T> struct segtree {
  T t[2 * N];
  segtree() { fill(t, t + 2 * N, 0); }

  void update(int i, T v, int x = 0, int l = 0, int r = N) {
    if (r - l == 1) {
      t[x] = v;
      return;
    }

    int m = (r + l) / 2;
    if (i < m)
      update(i, v, x * 2 + 1, l, m);
    else
      update(i, v, x * 2 + 2, m, r);
  }

  T sum(int ql, int qr, int x = 0, int l = 0, int r = N) {
    if (l >= ql && r <= qr)
      return t[x];
    if (qr <= l || ql >= r)
      return 0;
    int m = (r + l) / 2;
    return sum(ql, qr, x * 2 + 1, l, m) + sum(ql, qr, x * 2 + 2, m, r);
  }
};

int main() {
  int n;
  cin >> n;

  p[0] = 1;
  for (int i = 1; i <= n; i++)
    p[i] = (1ll * p[i - 1] * C) % mod;
  tp[0] = 1;
  for (int i = 1; i <= n; i++)
    tp[i] = tp[i - 1] * C;

  segtree<ull> t1;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    t1.update(i, tp[i] * x);
  }
  int m;
  cin >> m;
  while (m--) {
    int q, l, r, k;
    cin >> q >> l >> r >> k;
    l--, r--;
    if (q == 0) {
      for (int i = l; i <= r; i++)
        t1.update(i, tp[i] * k);
    } else {
      assert(q == 1);
      int answ = t1.sum(l, l + k) == t1.sum(r, r + k);
      cout << "-+"[answ];
    }
  }
}
