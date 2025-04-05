// semenInRussia 2025
#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <vector>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,fma,bmi2,tune=native")

using namespace std;

const int inf = 2e9 + 1000;

const int N = 1e6 + 100;
bool used[N];
int x[N], h[N], v[N];

// min, max, upd

vector<int> mn, mx;
int sz, n;

int getmin(int ql, int qr, int x, int l, int r) {
  if (ql <= l && r <= qr) {
    return mn[x];
  }
  if (ql >= r || qr <= l) {
    return +inf;
  }

  int m = (r + l) / 2;
  return min(getmin(ql, qr, 2 * x + 1, l, m), //
             getmin(ql, qr, 2 * x + 2, m, r));
}

int getmin(int ql, int qr) {
  if (qr - ql < 1) {
    return +inf;
  }
  return getmin(ql, qr, 0, 0, sz);
}

int getmax(int ql, int qr, int x, int l, int r) {
  if (ql <= l && r <= qr) {
    return mx[x];
  }
  if (ql >= r || qr <= l) {
    return -inf;
  }

  int m = (r + l) / 2;
  return max(getmax(ql, qr, 2 * x + 1, l, m), //
             getmax(ql, qr, 2 * x + 2, m, r));
}

int getmax(int ql, int qr) {
  if (qr - ql < 1) {
    return +inf;
  }
  return getmax(ql, qr, 0, 0, sz);
}

void upd(int i, int v1, int v2, int x, int l, int r) {
  if (r - l == 1) {
    mn[x] = v1;
    mx[x] = v2;
    return;
  }

  int m = (r + l) / 2;
  if (i < m) {
    upd(i, v1, v2, 2 * x + 1, l, m);
  } else {
    upd(i, v1, v2, 2 * x + 2, m, r);
  }
  mn[x] = min(mn[2 * x + 1], mn[2 * x + 2]);
  mx[x] = max(mx[2 * x + 1], mx[2 * x + 2]);
}

int prv(int j, int v, int x, int l, int r) {
  if (l >= j) {
    return -1;
  }
  if (mx[x] < v) {
    return -1;
  }
  if (r - l == 1) {
    return l;
  }
  int m = (l + r) / 2;
  int b = prv(j, v, 2 * x + 2, m, r);
  if (b != -1) {
    return b;
  }
  return prv(j, v, 2 * x + 1, l, m);
}

void upd(int i, int v, int v2) { upd(i, v, v2, 0, 0, sz); }
void del(int i) { upd(i, +inf, -inf, 0, 0, sz); }

int prv(int j, int v) {
  // get previous >= v
  int ans = prv(j, v, 0, 0, sz);
  return ans;
}

int nxt(int j, int v, int x, int l, int r) {
  if (l >= j && mn[x] > v) {
    return -1;
  }

  if (r <= j) {
    return -1;
  }

  if (r - l == 1) {
    assert(l >= j);
    return l;
  }

  int m = (r + l) / 2;
  int a = nxt(j, v, 2 * x + 1, l, m);
  if (a != -1) {
    return a;
  }
  return nxt(j, v, 2 * x + 2, m, r);
}

int nxt(int j, int v) {
  // get nxt <= v
  int ans = nxt(j + 1, v, 0, 0, sz);
  if (ans >= n) {
    ans = -1;
  }
  return ans;
}

void solve() {
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> x[i] >> h[i];
    v[i] = i;
  }

  sort(v, v + n, [](int i, int j) { return h[i] > h[j]; });

  sz = 1;
  while (sz < n) {
    sz *= 2;
  }
  mn.resize(2 * sz - 1);
  mx.resize(2 * sz - 1);

  for (int i = 0; i < n; i++) {
    upd(i, x[i] + h[i], x[i] - h[i]);
  }

  int ans = 0;

  for (int j = 0; j < n; j++) {
    int i = v[j];

    if (used[i]) {
      continue;
    }

    ans++;

    del(i);

    int _i = i;
    used[i] = 1;

    int v = x[i] - h[i];
    i = prv(i, v);

    while (i != -1) {
      del(i);
      used[i] = 1;
      i = prv(i, v);
    }

    i = _i;

    v = x[i] + h[i];
    i = nxt(i, v);

    while (i != -1) {
      del(i);

      used[i] = 1;
      i = nxt(i, v);
    }
  }

  cout << ans;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int tt = 1;
#ifdef home
  cin >> tt;
#endif

  while (tt--) {
    solve();
    cout << "\n";
  }

  return 0;
}
