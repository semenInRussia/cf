// semenInRussia 2025
#include <cassert>
#include <cstdint>
#include <iostream>

using namespace std;

const int N = 1e5 + 100;
int a[N], p[N];

const int L = 30;
int to[N * L][2];
int sz = 0;

int alloc() {
  to[sz][0] = to[sz][1] = -1;
  return sz++;
}

inline int bit(int x, int l) { return (x >> l) & 1; }

void insert(int p) {
  int x = 0;
  for (int l = L - 1; l >= 0; l--) {
    int c = bit(p, l);
    if (to[x][c] == -1) {
      to[x][c] = alloc();
    }
    x = to[x][c];
  }
}

int value(int p) {
  int x = 0;
  int v = p;
  for (int l = L - 1; l >= 0; l--) {
    int c = bit(p, l) ^ 1;
    if (to[x][c] == -1) {
      c ^= 1;
    }
    v ^= c << l;
    x = to[x][c];
  }
  return v;
}

void clear() {
  sz = 0;
  alloc();
}

int64_t f(int l, int r) {
  if (r - l == 1) {
    // return 1ll * a[l] * a[l]; // WTF? we can't use 1len segments?
    return 0;
  }
  if (r - l <= 0) {
    return 0;
  }

  int m = (l + r) / 2;
  auto ans = max(f(l, m), f(m, r));

  clear();
  for (int i = m; i < r; i++) {
    insert(p[i + 1]);
  }

  int mx = a[m - 1];
  for (int i = m - 1; i >= l; i--) {
    mx = max(mx, a[i]);
    ans = max(ans, 1ll * mx * value(p[i]));
  }

  clear();
  for (int i = m - 1; i >= l; i--) {
    insert(p[i]);
  }

  mx = a[m];
  for (int i = m; i < r; i++) {
    mx = max(mx, a[i]);
    ans = max(ans, 1ll * mx * value(p[i + 1]));
  }

  return ans;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(0);
#ifndef home
  freopen("maxxor.in", "r", stdin);
  freopen("maxxor.out", "w", stdout);
#endif
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    p[i + 1] = p[i] ^ a[i];
  }
  cout << f(0, n) << "\n";
}
