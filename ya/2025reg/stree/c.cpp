// semenInRussia 2025
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

struct node {
  int v0;
  int vk;
  int c;

  bool h = false;

  void apply(int x) {
    if (!h) {
      h = true;
      v0 = x;
      vk = x;
      c = 0;
    } else {
      c = max(c, vk - x);
      vk = x;
    }
  }
};

node operator*(node a, node b) {
  if (!a.h) {
    return b;
  }
  if (!b.h) {
    return a;
  }
  return {a.v0, b.vk, max({a.c, b.c, b.v0 - a.vk}), true};
}

struct tree {
  int sz;
  vector<node> t;

  tree(int n) {
    sz = 1;
    while (sz < n) {
      sz *= 2;
    }
    t.resize(2 * sz - 1);
    build(0, 0, sz);
  }

  void build(int x, int l, int r) {
    if (r - l == 1) {
      t[x].h = true;
      return;
    }
    int m = (l + r) / 2;
    build(2 * x + 1, l, m);
    build(2 * x + 2, m, r);
  }

  void push(int x) {
    t[2 * x + 1] = t[2 * x + 1] * t[x];
    t[2 * x + 2] = t[2 * x + 2] * t[x];
    t[x].h = false;
  }

  void upd(int ql, int qr, int v, int x, int l, int r) {
    if (ql <= l && r <= qr) {
      node op = {v, v, 0, true};
      t[x] = t[x] * op;
      return;
    }

    if (ql >= r || qr <= l) {
      return;
    }

    int m = (l + r) / 2;
    push(x);
    upd(ql, qr, v, 2 * x + 1, l, m);
    upd(ql, qr, v, 2 * x + 2, m, r);
  }

  void upd(int ql, int qr, int v) { upd(ql, qr, v, 0, 0, sz); }

  node qry(int i, int x, int l, int r) {
    if (r - l == 1) {
      return t[x];
    }

    int m = (l + r) / 2;
    if (i < m) {
      return qry(i, 2 * x + 1, l, m) * t[x];
    }
    return qry(i, 2 * x + 2, m, r) * t[x];
  }

  node qry(int i) { return qry(i, 0, 0, sz); }
};

int main() {
  int n, y, x;
  cin >> n >> y >> x;

  tree t(y + 1);

  vector<pair<int, pair<int, int>>> q(n);

  for (int i = 0; i < n; i++) {
    int v, l, r;
    cin >> v >> l >> r;
    q[i] = {v, {l, r}};
  }

  sort(q.begin(), q.end());

  for (auto [v, lr] : q) {
    auto [l, r] = lr;
    r++;
    auto d = t.qry(l);
    t.upd(l, r, v);
  }

  t.upd(0, y + 2, x);

  for (int i = 0; i <= y; i++) {
    cout << t.qry(i).c << "\n";
  }
}
