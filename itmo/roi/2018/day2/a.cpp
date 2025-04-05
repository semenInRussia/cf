// semenInRussia 2025
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

const int inf = 1e9 + 5;

// find j; max[j; i] = a[i], j <

struct stree {
  int sz = 1;
  int n;
  vector<int> mn, mx;

  stree(vector<int> &a) {
    n = (int)a.size();
    while (sz < n) {
      sz *= 2;
    }
    mn.resize(2 * sz - 1, +inf);
    mx.resize(2 * sz - 1, -inf);
    for (int i = 0; i < n; i++) {
      upd(i, a[i]);
    }
  }

  stree(int _n) {
    n = _n;
    while (sz < n) {
      sz *= 2;
    }
    mn.resize(2 * sz - 1, +inf);
    mx.resize(2 * sz - 1, -inf);
  }

  // prv>
  void upd(int j, int v, int x, int l, int r) {
    if (r - l == 1) {
      mx[x] = mn[x] = v;
      return;
    }

    int m = (l + r) / 2;
    if (j < m) {
      upd(j, v, 2 * x + 1, l, m);
    } else {
      upd(j, v, 2 * x + 2, m, r);
    }
    mn[x] = min(mn[2 * x + 1], mn[2 * x + 2]);
    mx[x] = max(mx[2 * x + 1], mx[2 * x + 2]);
  }

  pair<int, int> get_minmax(int l, int r) { return get_minmax(l, r, 0, 0, sz); }

  pair<int, int> get_minmax(int ql, int qr, int x, int l, int r) {
    if (ql <= l && r <= qr) {
      return {mn[x], mx[x]};
    }

    if (l >= qr || r <= ql) {
      return {+inf, -inf};
    }

    int m = (l + r) / 2;
    auto [a1, b1] = get_minmax(ql, qr, 2 * x + 1, l, m);
    auto [a2, b2] = get_minmax(ql, qr, 2 * x + 2, m, r);
    return {min(a1, a2), max(b1, b2)};
  }

  void upd(int j, int v) { return upd(j, v, 0, 0, sz); }

  int nxt(int j, int v, int x, int l, int r) {
    if (j >= r || mn[x] >= v) {
      return -1;
    }
    if (r - l == 1) {
      return l;
    }
    int m = (l + r) / 2;
    int a = nxt(j, v, 2 * x + 1, l, m);
    if (a == -1) {
      return nxt(j, v, 2 * x + 2, m, r);
    }
    return a;
  }

  int nxt(int j, int v) {
    int a = nxt(j, v, 0, 0, sz);
    return a == -1 ? n : a;
  }

  // min l that [l; r]=v
  int prv(int j, int v) { return prv(j, v, 0, 0, sz); }

  int prv(int j, int v, int x, int l, int r) {
    if (mx[x] <= v || j < l) {
      return -1;
    }
    if (r - l == 1) {
      return l;
    }

    int m = (l + r) / 2;
    int a = prv(j, v, 2 * x + 2, m, r);
    if (a == -1) {
      return prv(j, v, 2 * x + 1, l, m);
    }
    return a;
  }
};

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a) {
    cin >> x;
  }

  stree dp(n + 1);
  dp.upd(0, 0);

  stree st(a);

  vector<vector<int>> rig(n + 1);
  vector<int> val(n + 1);

  for (int i = 0; i < n; i++) {
    for (auto j : rig[i]) {
      dp.upd(j, +inf);
    }
    int l = st.prv(i, a[i]) + 1;
    int r = st.nxt(i, a[i]);
    rig[r].push_back(i + 1);
    int cur = min(dp.get_minmax(l + 1, i + 1).first, val[i] + 1);
    dp.upd(i + 1, cur);
    val[i + 1] = cur;
  }
  cout << dp.get_minmax(n, n + 1).first;
}
