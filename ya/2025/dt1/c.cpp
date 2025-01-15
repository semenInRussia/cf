// semenInRussia 2025
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

struct node {
  vector<int> s, p;
  ll value = 0ll;
  int x, len = 1;

  node(int v = 0) {
    s.resize(30);
    p.resize(30);
    value = x = v;
    len = 1;
    for (int i = 0; i < 30; i++) {
      s[i] = p[i] = (x >> i) & 1;
    }
  }
};

const node zero() {
  node c;
  c.len = 0;
  return c;
}

node operator*(node a, node b) {
  node c;
  c.len = a.len + b.len;
  c.x = a.x ^ b.x;

  auto &val = c.value;
  val = a.value + b.value;

  c.p = a.p;
  c.s = b.s;

  for (int i = 0; i < 30; i++) {
    c.p[i] += (a.x >> i) & 1 ? b.len - b.p[i] : b.p[i];
    c.s[i] += (b.x >> i) & 1 ? a.len - a.s[i] : a.s[i];

    val += (1ll << i) * (a.len - a.s[i]) * b.p[i];
    val += (1ll << i) * a.s[i] * (b.len - b.p[i]);
  }
  return c;
}

struct tree {
  vector<node> t;
  int sz;

  tree(int n) {
    sz = 1;
    while (sz < n) {
      sz *= 2;
    }
    t.resize(2 * sz);
    build(0, 0, sz);
  }

  void build(int x, int l, int r) {
    if (r - l == 1) {
      t[x].len = 1;
      t[x].value = t[x].x = 0;
      return;
    }
    int m = (r + l) / 2;
    build(2 * x + 1, l, m);
    build(2 * x + 2, m, r);
    t[x] = t[2 * x + 1] * t[2 * x + 2];
  }

  void upd(int i, int v, int x, int l, int r) {
    if (r - l == 1) {
      t[x] = node(v);
      return;
    }
    int m = (r + l) / 2;
    if (i < m) {
      upd(i, v, 2 * x + 1, l, m);
    } else {
      upd(i, v, 2 * x + 2, m, r);
    }
    t[x] = t[2 * x + 1] * t[2 * x + 2];
  }

  void upd(int i, int v) { upd(i, v, 0, 0, sz); }

  node qry(int ql, int qr, int x, int l, int r) {
    if (ql <= l && r <= qr) {
      return t[x];
    }
    if (ql >= r || qr <= l) {
      return zero();
    }
    int m = (r + l) / 2;
    return qry(ql, qr, 2 * x + 1, l, m) * qry(ql, qr, 2 * x + 2, m, r);
  }

  node qry(int ql, int qr) { return qry(ql, qr, 0, 0, sz); }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  //--

  int n, q;
  cin >> n >> q;

  tree t(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    t.upd(i, x);
  }

  for (int i = 0; i < q; i++) {
    int typ;
    cin >> typ;
    if (typ == 1) {
      int i, v;
      cin >> i >> v;
      t.upd(i - 1, v);
    } else {
      int l, r;
      cin >> l >> r;
      cout << t.qry(l - 1, r).value << "\n";
    }
  }
}
