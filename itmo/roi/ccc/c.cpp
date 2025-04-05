// semenInRussia 2025
#pragma GCC optimize("O3,unroll-loops")
#include <cstdint>
#include <iostream>
#include <vector>
#pragma GCC target("avx2")

using namespace std;

const int N = 1 << 18, L = 20;
int c[N];

int n, q;

int t[2 * N];

void upd(int j, int v, int x = 0, int l = 0, int r = N) {
  if (r - l == 1) {
    t[x] = v;
    return;
  }
  int m = (l + r) / 2;
  if (j < m) {
    upd(j, v, 2 * x + 1, l, m);
  } else {
    upd(j, v, 2 * x + 2, m, r);
  }
  t[x] = max(t[2 * x + 1], t[2 * x + 2]);
}

// nxt >=
int nxt(int j, int64_t v, int x = 0, int l = 0, int r = N) {
  if (j + 1 >= r || t[x] < v) {
    return -1;
  }
  if (r - l == 1) {
    return l;
  }
  int m = (l + r) / 2;
  int a = nxt(j, v, 2 * x + 1, l, m);
  if (a != -1) {
    return a;
  }
  return nxt(j, v, 2 * x + 2, m, r);
}

struct fenw {
  vector<int64_t> t;
  int n;
  fenw(int sz) {
    n = sz;
    t.resize(n + 1);
  }

  void add(int r, int v) {
    r++;
    for (; r <= n; r += r & -r) {
      t[r] += v;
    }
  }

  int64_t pref(int r) {
    int64_t s = 0;
    for (; r > 0; r -= r & -r) {
      s += t[r];
    }
    return s;
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  cin >> n >> q;
  fenw f(n + 1);

  for (int i = 0; i < n; i++) {
    cin >> c[i];
    upd(i, c[i]);
    f.add(i, c[i]);
  }

  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int k, v;
      cin >> k >> v;
      --k;
      int old = c[k];
      c[k] = v;
      upd(k, v);
      f.add(k, -old + c[k]);
    } else {
      int l, r;
      cin >> l >> r;
      --l;
      int j = l;
      for (int i = l + 1; i < r && i != -1; i = nxt(i, f.pref(i) - f.pref(l))) {
        auto p = f.pref(i) - f.pref(l);
        if (p <= c[i]) {
          j = i;
        }
      }
      cout << j + 1 << "\n";
    }
  }
}
