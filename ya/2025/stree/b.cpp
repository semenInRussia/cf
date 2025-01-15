// semenInRussia 2025
#include <cstdint>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const int inf = 1e7;

struct tree {
  int sz, n;
  vector<int> t, arr;

  tree(vector<int> &a) : arr(a) {
    n = (int)a.size();
    sz = 1;
    while (sz < n) {
      sz *= 2;
    }
    t.resize(2 * sz - 1);
    build(0, 0, sz);
  }

  void build(int x, int l, int r) {
    if (r - l == 1) {
      if (l < (int)arr.size()) {
        t[x] = arr[l];
      } else {
        t[x] = -inf;
      }
      return;
    }

    int m = (l + r) / 2;
    build(2 * x + 1, l, m);
    build(2 * x + 2, m, r);
    t[x] = min(t[2 * x + 1], t[2 * x + 2]);
  }

  int qry(int ql, int qr, int x, int l, int r) {
    if (ql <= l && r <= qr) {
      return t[x];
    }

    if (ql >= r || qr <= l) {
      return +inf;
    }

    int m = (l + r) / 2;

    return min(qry(ql, qr, 2 * x + 1, l, m), qry(ql, qr, 2 * x + 2, m, r));
  }

  int qry(int ql, int qr) {
    if (qr - ql == 0) {
      return +inf;
    }
    return qry(ql, qr, 0, 0, sz);
  }
};

int main() {
  freopen("minsum.in", "r", stdin);
  freopen("minsum.out", "w", stdout);
  int n;
  cin >> n;

  vector<int> a(n);

  for (int &x : a) {
    cin >> x;
  }

  int64_t ans = 0;

  tree t(a);

  for (int i = 0; i < n; i++) {
    // find L, R that on [L, R] a[i] - minimum

    int l = i;
    int r = n;

    l = -1;
    r = i + 1;
    // find max j; qry(j, i) <= a[i]

    while (r - l > 1) {
      int m = (l + r) / 2;
      bool ok = m == i || t.qry(m, i) >= a[i];
      if (ok) {
        r = m;
      } else {
        l = m;
      }
    }

    int L = r;

    l = i - 1;
    r = n;

    while (r - l > 1) {
      int m = (l + r) / 2;
      bool ok = m == i || t.qry(i + 1, m + 1) > a[i];
      if (ok) {
        l = m;
      } else {
        r = m;
      }
    }

    int R = l;

    ans += 1ll * (R - i + 1) * (i - L + 1) * a[i];
  }

  cout << ans;
}
