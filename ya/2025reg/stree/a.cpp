// semenInRussia 2025
#include <cstdint>
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
      }
      return;
    }

    int m = (l + r) / 2;
    build(2 * x + 1, l, m);
    build(2 * x + 2, m, r);
    t[x] = max(t[2 * x + 1], t[2 * x + 2]);
  }

  void upd(int i, int v) { upd(i, v, 0, 0, sz); }

  void upd(int i, int v, int x, int l, int r) {
    if (r - l == 1) {
      t[x] = v;
      return;
    }

    int m = (l + r) / 2;
    if (i < m) {
      upd(i, v, 2 * x + 1, l, m);
    } else {
      upd(i, v, 2 * x + 2, m, r);
    }
    t[x] = max(t[2 * x + 1], t[2 * x + 2]);
  }

  int qry(int ql, int qr, int x, int l, int r) {
    if (ql <= l && r <= qr) {
      return t[x];
    }

    if (ql >= r || qr <= l) {
      return -inf;
    }

    int m = (l + r) / 2;

    return max(qry(ql, qr, 2 * x + 1, l, m), qry(ql, qr, 2 * x + 2, m, r));
  }

  int qry(int ql, int qr) {
    if (qr - ql == 0) {
      return +inf;
    }
    return qry(ql, qr, 0, 0, sz);
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  freopen("nearandmore.in", "r", stdin);
  freopen("nearandmore.out", "w", stdout);
  int n, m;
  cin >> n >> m;

  vector<int> a(n);

  for (int &x : a) {
    cin >> x;
  }

  tree t(a);

  for (int i = 0; i < m; i++) {
    int typ;
    cin >> typ;
    if (typ == 0) {
      int j, v;
      cin >> j >> v;
      j--;
      t.upd(j, v);
    } else {
      int j, x;
      cin >> j >> x;
      j--;

      int l = j - 1;
      int r = n;

      // min k; qry(i, k + 1) >= x

      while (r - l > 1) {
        int m = (l + r) / 2;
        // cout << "check " << m << "; " << t.qry(j, m + 1) << "\n";
        if (t.qry(j, m + 1) >= x) {
          r = m;
        } else {
          l = m;
        }
      }

      if (t.qry(j, r + 1) < x) {
        cout << "-1\n";
      } else {
        cout << r + 1 << "\n";
      }
    }
  }
}
