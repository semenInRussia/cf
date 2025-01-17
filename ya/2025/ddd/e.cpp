// semenInRussia 2025
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <numeric>
#include <vector>

#pragma GCC optimize("Ofast")

using namespace std;

template <typename T> T &setmax(T &v, T op) { return v = max(v, op); }

struct node {
  int64_t best, sum, gc;
  vector<pair<int64_t, int64_t>> pref, suf;
  bool empty;

  node() {
    best = 0;
    empty = true;
  }
};

void cleanup(vector<pair<int64_t, int64_t>> &a) {
  int j = 0;
  int n = (int)a.size();
  sort(a.begin(), a.end());
  for (int i = 0; i < n; i++) {
    if (a[i].first != a[j].first) {
      j++;
    }
    a[j] = a[i];
  }
  a.resize(j + 1);
}

node operator*(node a, node b) {
  if (a.empty) {
    return b;
  }
  if (b.empty) {
    return a;
  }

  node c;

  c.empty = false;
  c.sum = a.sum + b.sum;
  c.gc = gcd(a.gc, b.gc);

  c.best = max(a.best, b.best);

  for (auto [g1, s1] : a.suf) {
    for (auto [g2, s2] : b.pref) {
      c.best = max(c.best, gcd(g1, g2) * (s1 + s2));
    }
  }

  c.pref = a.pref;

  for (auto [g1, s1] : b.pref) {
    c.pref.push_back({gcd(a.gc, g1), a.sum + s1});
  }

  cleanup(c.pref);

  c.suf = b.suf;

  for (auto [g1, s1] : a.suf) {
    c.suf.push_back({gcd(b.gc, g1), b.sum + s1});
  }

  cleanup(c.suf);

  return c;
}

struct tree {
  vector<int> a;
  vector<node> t;
  int sz;

  tree(vector<int> &_a) {
    a = _a;
    sz = 1;
    while (sz < (int)a.size()) {
      sz *= 2;
    }
    t.resize(2 * sz - 1);
    build(0, 0, sz);
  }

  void build(int x, int l, int r) {
    if (r - l == 1) {
      if (l < (int)a.size()) {
        t[x].gc = t[x].sum = a[l];
        t[x].suf.push_back({a[l], a[l]});
        t[x].pref.push_back({a[l], a[l]});
        t[x].best = 1ll * a[l] * a[l];
        t[x].empty = false;
      }
      return;
    }

    int m = (l + r) / 2;
    build(2 * x + 1, l, m);
    build(2 * x + 2, m, r);
    t[x] = t[2 * x + 1] * t[2 * x + 2];
  }

  node qry(int ql, int qr) { return qry(ql, qr, 0, 0, sz); }

  node qry(int ql, int qr, int x, int l, int r) {
    if (ql <= l && r <= qr) {
      return t[x];
    }

    if (ql >= r || l >= qr) {
      return node();
    }

    int m = (l + r) / 2;
    return qry(ql, qr, 2 * x + 1, l, m) * qry(ql, qr, 2 * x + 2, m, r);
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n, q;
  cin >> n >> q;

  vector<int> a(n);

  for (int &x : a) {
    cin >> x;
  }

  tree t(a);

  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    l--;
    cout << t.qry(l, r).best << "\n";
  }
}
