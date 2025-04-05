// semenInRussia 2025
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

const int64_t inf = 1e18 + 10;

struct tree {
  vector<int64_t> t, lazy;
  int sz;

  tree(int n) {
    sz = 1;
    while (sz < n) {
      sz *= 2;
    }
    t.resize(2 * sz - 1);
    lazy.resize(2 * sz - 1);
  }

  void apply(int x, int64_t v) { // += v
    t[x] += v;
    lazy[x] += v;
  }

  void push(int x) {
    apply(2 * x + 1, lazy[x]);
    apply(2 * x + 2, lazy[x]);
    lazy[x] = 0;
  }

  void upd(int i, int64_t v) { upd(i, v, 0, 0, sz); }

  void upd(int i, int64_t v, int x, int l, int r) {
    if (r - l == 1) {
      t[x] = v;
      return;
    }
    push(x);
    int m = (l + r) / 2;
    if (i < m) {
      upd(i, v, 2 * x + 1, l, m);
    } else {
      upd(i, v, 2 * x + 2, m, r);
    }
    t[x] = min(t[2 * x + 1], t[2 * x + 2]);
  }

  // [ql; qr) += v
  void add(int ql, int qr, int64_t v, int x, int l, int r) {
    if (ql <= l && r <= qr) {
      apply(x, v);
      return;
    }

    if (l >= qr || r <= ql) {
      return;
    }

    int m = (r + l) / 2;

    push(x);
    add(ql, qr, v, 2 * x + 1, l, m);
    add(ql, qr, v, 2 * x + 2, m, r);

    t[x] = min(t[2 * x + 1], t[2 * x + 2]);
  }

  void add(int ql, int qr, int64_t v) { add(ql, qr, v, 0, 0, sz); }

  int64_t qry(int ql, int qr) { return qry(ql, qr, 0, 0, sz); }

  int64_t qry(int ql, int qr, int x, int l, int r) {
    if (ql <= l && r <= qr) {
      return t[x];
    }

    if (ql >= r || qr <= l) {
      return +inf;
    }

    int m = (l + r) / 2;
    push(x);
    return min(qry(ql, qr, 2 * x + 1, l, m), //
               qry(ql, qr, 2 * x + 2, m, r));
  }

  int64_t operator[](int i) { return qry(i, i + 1); }
};

using pii = pair<int64_t, int64_t>;

int n;
const int N = 2e5;
pii p[N];

int64_t dist(int i, int j) {
  if (min(i, j) < 0 || max(i, j) >= n) {
    return 0;
  }
  pii a = p[i];
  pii b = p[j];
  return abs(a.first - b.first) + abs(a.second - b.second);
}

void upd1(tree &t, int64_t d, int i) {
  if (i == -1 || i == n) {
    return;
  }

  t.upd(i, d - dist(i, i - 1) - dist(i, i + 1) + dist(i - 1, i + 1));
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> p[i].first >> p[i].second;
  }

  if (n <= 2) {
    int q;
    cin >> q;
    while (q--) {
      string t;
      int i, x, y;
      cin >> t >> i >> x >> y;
      cout << "0\n";
    }
    return 0;
  }

  int64_t d = 0;
  for (int i = 0; i + 1 < n; i++) {
    d += dist(i, i + 1);
  }

  tree f(n + 10);
  for (int i = 0; i < n; i++) {
    f.upd(i, d - dist(i, i - 1) - dist(i, i + 1) + dist(i - 1, i + 1));
  }

  int q;
  cin >> q;
  while (q--) {
    string t;
    int i, x, y;
    cin >> t >> i >> x >> y;
    i--;

    int64_t w1 = dist(i, i + 1);
    int64_t w2 = dist(i, i - 1);

    d -= w1 + w2;

    auto old = f[i];
    f.add(0, n, -(w1 + w2));

    p[i] = {x, y};

    w1 = dist(i, i + 1);
    w2 = dist(i, i - 1);

    d += w1 + w2;

    f.add(0, n, w1 + w2);

    upd1(f, d, i - 1);
    upd1(f, d, i + 1);
    f.upd(i, old);

    cout << min(d, f.qry(0, n)) << "\n";
  }
}
