// semenInRussia 2025
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

// with lazy propogonate
//
// sum [l, r]
// [l, r] +=
struct tree {
  vector<int64_t> t, lazy;

  int sz, n;

  tree(int _n) {
    n = _n;
    sz = 1;
    while (sz < n) {
      sz *= 2;
    }
    t.resize(2 * sz - 1, 0);
  }

  void upd(int i, int64_t v) { upd(i, i + 1, v); }

  void upd(int ql, int qr, int64_t v) { upd(ql, qr, v, 0, 0, sz); }

  void apply(int x, int l, int r, int64_t v) {
    t[x] += v * (r - l);
    lazy[x] += v;
  }

  void push(int x, int l, int r) {
    if (lazy[x]) {
      int m = (l + r) / 2;
      apply(2 * x + 1, l, m, lazy[x]);
      apply(2 * x + 2, m, r, lazy[x]);
      lazy[x] = 0;
    }
  }

  void upd(int ql, int qr, int64_t v, int x, int l, int r) {
    if (ql <= l && r <= qr) {
      apply(x, l, r, v);
      return;
    }

    if (ql >= r || qr <= l) {
      return;
    }

    int m = (l + r) / 2;
    push(x, l, r);

    upd(ql, qr, v, 2 * x + 1, l, m);
    upd(ql, qr, v, 2 * x + 2, m, r);
    t[x] = t[2 * x + 1] + t[2 * x + 2];
  }

  int64_t qry(int ql, int qr) { return qry(ql, qr, 0, 0, sz); }

  int64_t qry(int ql, int qr, int x, int l, int r) {
    if (ql <= l && r <= qr) {
      return t[x];
    }

    if (ql >= r || qr <= l) {
      return 0;
    }

    int m = (l + r) / 2;
    push(x, l, r);
    return qry(ql, qr, 2 * x + 1, l, m) + qry(ql, qr, 2 * x + 2, m, r);
  }
};
