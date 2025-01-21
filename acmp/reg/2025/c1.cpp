// semenInRussia 2025
#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

const int N = 2e5;
int h[N];

struct tree1 {
  int n, sz;

  struct node {
    pair<int, int> mx = {-1, 0};
    int64_t sum = 0;

    node operator*(node other) { return {max(other.mx, mx), sum + other.sum}; }
  };

  vector<node> t;

  tree1(int _n) {
    n = _n;
    sz = 1;
    while (sz < n) {
      sz *= 2;
    }
    t.resize(2 * sz - 1);
    build(0, 0, sz);
  }

  void build(int x, int l, int r) {
    if (r - l == 1) {
      t[x] = {{h[l], l}, h[l]};
      return;
    }
    int m = (l + r) / 2;
    build(2 * x + 1, l, m);
    build(2 * x + 2, m, r);
    t[x] = t[2 * x + 1] * t[2 * x + 2];
  }

  node qry(int l, int r) { return qry(l, r, 0, 0, sz); }

  node qry(int ql, int qr, int x, int l, int r) {
    if (ql <= l && r <= qr) {
      return t[x];
    }

    if (ql >= r || qr <= l) {
      return node();
    }

    int m = (l + r) / 2;
    return qry(ql, qr, 2 * x + 1, l, m) * qry(ql, qr, 2 * x + 2, m, r);
  }
};

struct tree2 {
  int sz, n;

  vector<int64_t> t, lazy;
  tree2(int _n) {
    n = _n;
    sz = 1;
    while (sz < n) {
      sz *= 2;
    }
    t.resize(2 * sz - 1);
    lazy.resize(2 * sz - 1, -1);
  }

  void apply(int x, int len, int v) {
    t[x] = 1ll * len * v;
    lazy[x] = v;
  }

  void push(int x, int len) {
    if (lazy[x] != -1) {
      apply(2 * x + 1, len / 2, lazy[x]);
      apply(2 * x + 2, len / 2, lazy[x]);
      lazy[x] = -1;
    }
  }

  int nxt(int l, int r, int v) {
    int r1 = r;
    l--;
    // get last j;
    // sum(j, j + 1) <= v
    while (r - l > 1) {
      int m = (l + r) / 2;
      if (sum(m, m + 1) <= v) {
        l = m;
      } else {
        r = m;
      }
    }
    if (l == r1) {
      l--;
    }
    return l;
  }

  int prv(int l, int r, int v) {
    // get first;
    int l1 = l;
    l--;
    while (r - l > 1) {
      int m = (l + r) / 2;
      if (sum(m, m + 1) <= v) {
        r = m;
      } else {
        l = m;
      }
    }
    if (r < l1) {
      r++;
    }
    return r;
  }

  // sum
  int64_t sum(int l, int r) { return sum(l, r, 0, 0, sz); }

  int64_t sum(int ql, int qr, int x, int l, int r) {
    if (l >= qr || r <= ql) {
      return 0;
    }
    if (ql <= l && r <= qr) {
      return t[x];
    }

    int m = (l + r) / 2;
    push(x, r - l);
    return sum(ql, qr, 2 * x + 1, l, m) + sum(ql, qr, 2 * x + 2, m, r);
  }

  // upd
  void change(int l, int r, int v) { return change(l, r, v, 0, 0, sz); }

  void change(int ql, int qr, int v, int x, int l, int r) {
    if (r <= ql || l >= qr) {
      return;
    }
    if (ql <= l && r <= qr) {
      apply(x, r - l, v);
      return;
    }

    int m = (l + r) / 2;
    push(x, r - l);
    change(ql, qr, v, 2 * x + 1, l, m);
    change(ql, qr, v, 2 * x + 2, m, r);
    t[x] = t[2 * x + 1] + t[2 * x + 2];
  }
};

struct fenw {
  int n;
  vector<int> t;

  fenw(int _n) : n(_n) { t.resize(n + 1); }

  void add(int j, int v) {
    j++;
    for (; j <= n; j += j & -j) {
      t[j] += v;
    }
  }

  int sum(int r) {
    int s = 0;
    for (; r > 0; r -= r & -r) {
      s += t[r];
    }
    return s;
  }

  int find(int k) {
    int l = -1;
    int r = n;
    while (r - l > 1) {
      int m = (l + r) / 2;
      if (sum(m) >= k) {
        r = m;
      } else {
        l = m;
      }
    }
    return r;
  }
};

void solve() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }

  tree1 t(n);
  tree2 pref(n), suf(n);

  for (int i = 0; i < n; i++) {
    pref.change(i, i + 1, h[i]);
    suf.change(i, i + 1, h[i]);
  }

  fenw s(n);
  for (int i = 0; i < n; i++) {
    s.add(i, +1);
  }

  auto join = [&](int k) -> pair<int, int> {
    int l = s.find(k);
    int r = s.find(k + 1);
    int r2 = s.find(k + 2);

    s.add(r - 1, -1);

    int v, j;

    v = t.qry(l, r).mx.first;
    j = pref.nxt(r, r2, v);
    pref.change(r, j + 1, v);

    v = t.qry(r, r2).mx.first;
    j = suf.prv(l, r, v);
    suf.change(j, r, v);

    r = s.find(k + 1);

    return {l, r};
  };

  auto answ = [&](int l, int r) {
    int j = t.qry(l, r).mx.second;
    return pref.sum(l, j) + suf.sum(j, r) - t.qry(l, r).sum;
  };

  for (int j = 1; j < n; j++) {
    int k;
    cin >> k;
    k--;
    auto [l, r] = join(k);
    cout << answ(l, r) << "\n";
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  cout.tie(nullptr);
  int tt = 1;
#ifdef home
  cin >> tt;
#endif
  while (tt--) {
    solve();
    cout << "\n";
  }
}
