// semenInRussia 2025
#include <cassert>
#include <cstdint>
#include <iostream>
#include <vector>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,fma,bmi2,tune=native")

using namespace std;

const int mod = 1e9 + 7;

struct mi {
  int v;
  mi(int64_t x = 0) : v(x % mod) { v += mod * (x < 0); }
  explicit operator int() { return v; }
};

mi mi2, mi6;

mi operator*(mi a, mi b) { return mi(1ll * a.v * b.v); }
mi &operator*=(mi &a, mi b) { return a = a * b; }

mi operator+(mi a, mi b) { return mi(1ll * a.v + b.v); }
mi &operator+=(mi &a, mi b) { return a = a + b; }

mi operator-(mi a, mi b) { return mi(a.v - b.v); }
mi &operator-=(mi &a, mi b) { return a = a - b; }
mi pow(mi x, int64_t k) {
  mi ans = 1;
  while (k) {
    if (k & 1) {
      ans *= x;
    }
    k >>= 1;
    x *= x;
  }
  return ans;
}

mi inv(mi x) { return pow(x, mod - 2); }
mi operator/(mi a, mi b) { return a * inv(b); }

istream &operator>>(istream &in, mi &v) { return in >> v.v; }
ostream &operator<<(ostream &out, mi v) { return out << v.v; }

const int N = 5e5 + 100;
mi s[N];
mi b[N];
mi q[N];

int a[N];

struct node {
  mi b;
  mi s;
  mi q;

  node() {
    b = 0;
    s = 0;
    q = 0;
  }
};

node operator*(node s, node t) {
  node c;
  c.b = s.b + t.b;
  c.q = s.q + t.q;
  c.s = s.s + t.s;
  return c;
}

mi sqrs(mi n) { return n * (n + 1) * (n * 2 + 1) * mi6; }

struct tree {
  int sz;

  vector<node> t;
  vector<int> lazy;

  tree(int n) {
    sz = 1;
    while (sz < n) {
      sz *= 2;
    }
    t.resize(2 * sz - 1);
    lazy.resize(2 * sz - 2, -1);
  }

  void apply(int x, int l, int r, int v) {
    lazy[x] = v;
    t[x].b = mi(v) * (r - l);
    // sum of squares from l+1 to r+1
    t[x].s = (sqrs(r) - sqrs(l)) * v;
    mi n = r - l;
    t[x].q = (n * (l + 1 + r) * mi2) * v;
  }

  void push(int x, int l, int r) {
    if (lazy[x] == -1) {
      return;
    }
    int m = (l + r) / 2;
    apply(2 * x + 1, l, m, lazy[x]);
    apply(2 * x + 2, m, r, lazy[x]);
    lazy[x] = -1;
  }

  node qry(int ql, int qr, int x, int l, int r) {
    if (ql <= l && r <= qr) {
      return t[x];
    }

    if (l >= qr || r <= ql) {
      return node();
    }

    int m = (l + r) / 2;
    push(x, l, r);
    return qry(ql, qr, 2 * x + 1, l, m) * qry(ql, qr, 2 * x + 2, m, r);
  }

  node qry(int ql, int qr) { return qry(ql, qr, 0, 0, sz); }

  void change(int ql, int qr, int v, int x, int l, int r) {
    if (ql <= l && r <= qr) {
      apply(x, l, r, v);
      return;
    }

    if (ql >= r || qr <= l) {
      return;
    }

    int m = (l + r) / 2;
    push(x, l, r);
    change(ql, qr, v, 2 * x + 1, l, m);
    change(ql, qr, v, 2 * x + 2, m, r);
    t[x] = t[x * 2 + 1] * t[x * 2 + 2];
  }

  void change(int ql, int qr, int v) { return change(ql, qr, v, 0, 0, sz); }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  mi2 = mi(1) / 2;
  mi6 = mi(1) / 6;

  tree st(n);

  node d;

  for (int i = 0; i < n; i++) {
    st.change(i, i + 1, a[i]);
    d = st.qry(i, i + 1);
  }

  auto qry = [&](int l, int r) {
    node v = st.qry(l, r);
    mi ll = mi(l) * l;
    mi l2 = mi(l) * 2;
    return v.s - v.q * l2 + v.b * ll;
  };

  for (int i = 0; i < m; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      int l, r, v;
      cin >> l >> r >> v;
      st.change(l - 1, r, v);
      continue;
    }
    int l, r;
    cin >> l >> r;
    cout << (qry(l - 1, r)) << "\n";
  }
}
