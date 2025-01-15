// semenInRussia 2025
#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <set>
#include <vector>

// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,fma,bmi2,tune=native")

using namespace std;

const int64_t inf = 1e9 + 100;

struct tree {
  int n, sz;

  vector<pair<int64_t, int>> t;
  vector<int64_t> lazy;
  vector<int> a;

  tree(vector<int> &_a) {
    a = _a;
    n = (int)a.size();
    sz = 1;
    while (sz <= n) {
      sz *= 2;
    }
    t.resize(2 * sz);
    lazy.resize(2 * sz);
    build(0, 0, sz);
  }

  void build(int x, int l, int r) {
    if (r - l == 1) {
      if (l < n) {
        t[x] = {a[l], l};
      } else {
        t[x] = {0, l};
      }
      return;
    }

    int m = (l + r) / 2;
    build(2 * x + 1, l, m);
    build(2 * x + 2, m, r);
    t[x] = min(t[2 * x + 1], t[2 * x + 2]);
  }

  void apply(int x, int64_t v) {
    lazy[x] += v;
    t[x].first += v;
  }

  void push(int x) {
    apply(2 * x + 1, lazy[x]);
    apply(2 * x + 2, lazy[x]);
    lazy[x] = 0;
  }

  // getmin
  pair<int64_t, int> qry(int ql, int qr, int x, int l, int r) {
    if (ql <= l && r <= qr) {
      return t[x];
    }
    if (ql >= r || qr <= l) {
      return {+inf, -1};
    }

    push(x);
    int m = (l + r) / 2;
    return min(qry(ql, qr, 2 * x + 1, l, m), //
               qry(ql, qr, 2 * x + 2, m, r));
  }

  pair<int64_t, int> qry(int ql, int qr) { return qry(ql, qr, 0, 0, sz); }

  // add [l; r) += v

  void add(int ql, int qr, int64_t v, int x, int l, int r) {
    if (ql <= l && r <= qr) {
      apply(x, v);
      return;
    }
    if (ql >= r || qr <= l) {
      return;
    }

    int m = (l + r) / 2;
    push(x);
    add(ql, qr, v, 2 * x + 1, l, m);
    add(ql, qr, v, 2 * x + 2, m, r);
    t[x] = min(t[2 * x + 1], t[2 * x + 2]);
  }

  void add(int ql, int qr, int64_t v) { add(ql, qr, v, 0, 0, sz); }

  // nxt0

  int nxt(int j, int x, int l, int r) {
    if (r <= j) {
      return -1;
    }

    if (t[x].first > 0) {
      return -1;
    }

    if (l >= j) {
      return t[x].second;
    }

    push(x);

    int m = (l + r) / 2;
    int v = nxt(j, 2 * x + 1, l, m);
    if (v != -1) {
      return v;
    }
    return nxt(j, 2 * x + 2, m, r);
  }

  int nxt(int j) { return nxt(j, 0, 0, sz); }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  //--

  int n;
  cin >> n;

  vector<int> a(n);

  for (int &x : a) {
    cin >> x;
  }

  tree t(a);

  vector<pair<int64_t, pair<int, int>>> op;

  set<int> q;
  for (int i = 0; i < n; i++) {
    q.insert(i);
  }

  while (!q.empty()) {
    int j = *q.begin();

    if (t.qry(j, j + 1).first == 0) {
      q.erase(j);
      continue;
    }

    int r = t.nxt(j) - j;

    assert(j + r <= n);
    assert(t.qry(j + r, j + r + 1).first == 0);

    auto [ai, i] = t.qry(j, j + r);
    assert(t.qry(i, i + 1).first == ai);
    assert(ai > 0);

    assert(i != -1);
    // int v = t.qry(0, 2).first;

    assert(i >= j && i < j + r);

    t.add(j, j + r, -ai);

    // assert(t.qry(i, i + 1).first == 0);

    auto amt = ai * r;

    if (amt > 0) {
      op.push_back({amt, {j, r}});
    }

    // assert(q.count(i));
    if (q.count(i)) {
      q.erase(i);
    }
  }

  int k = (int)op.size();

  vector<int64_t> pref(k + 1);

  for (int i = 0; i < k; i++) {
    pref[i + 1] = pref[i] + op[i].first;
  }

  // int pos = 0;
  // for (auto [x, jr] : op) {
  //   cout << "(" << (pos++) << ")";
  //   auto [j, r] = jr;
  //   cout << x << ": from " << j << " with len=" << r;
  //   cout << "[" << pref[pos - 1] << "; " << pref[pos - 1] + op[pos - 1].first
  //        << ")\n";
  // }

  // return 0;

  int qu;
  cin >> qu;

  while (qu--) {
    int64_t x;
    cin >> x;
    x--;

    int l = -1;
    int r = k;
    while (r - l > 1) {
      int m = (l + r) / 2;
      if (x >= pref[m]) {
        l = m;
      } else {
        r = m;
      }
    }

    auto [j, len] = op[l].second;
    auto p = pref[l];

    // cout << "choose " << l << "\n";

    int64_t v = (x - p) % len;
    cout << (j + v + 1) << "\n";
  }
}
