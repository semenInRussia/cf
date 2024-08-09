// semenInRussia 2024
#include <cassert>
#include <iostream>
using namespace std;
using pii = pair<int, int>;

const int N = 1 << 17, mod = 1e9 + 123;

int C = 1; // max color + 1
int p[N], n;
int pp[N]; // pp[i] is sum of p[0], p[1], .., p[i-1]
struct node {
  int sum = 0;
  int l = 0;
  int len = 0;

  bool lazy = 0;
  int k = -1;
};

bool operator==(node a, node b) {
  return a.len == b.len &&
         ((1ll * a.sum * p[n - a.l] % mod) == (1ll * b.sum * p[n - b.l] % mod));
}
node operator+(node a, node b) {
  a.sum = (1ll * p[n - a.l] * a.sum) % mod;
  a.l = n;

  b.sum = (1ll * p[n - b.l] * b.sum) % mod;
  b.l = n;

  b.sum = (1ll * p[a.len] * b.sum) % mod;
  return {(a.sum + b.sum) % mod, n, a.len + b.len};
}

node t[2 * N];

void build(int x = 0, int l = 0, int r = N) {
  t[x] = {0, min(n, l), r - l};
  if (r - l == 1)
    return;
  int m = (r + l) / 2;
  build(x * 2 + 1, l, m);
  build(x * 2 + 2, m, r);
}

void chg(int x, int v) {
  int l = t[x].l, len = t[x].len;
  int sum = 1ll * pp[len] * v % mod;
  t[x].sum = 1ll * sum * p[l] % mod;
}

void push(int x) {
  if (!t[x].lazy || t[x].len == 1)
    return;
  t[x].lazy = 0;
  int k = t[x].k;
  t[x * 2 + 1].lazy = t[x * 2 + 2].lazy = 1;
  t[x * 2 + 1].k = t[x * 2 + 2].k = k;
  chg(x * 2 + 1, k);
  chg(x * 2 + 2, k);
}

void update(int ql, int qr, int v, int x = 0, int l = 0, int r = N) {
  if (ql >= r || qr <= l)
    return;
  if (l >= ql && r <= qr) {
    chg(x, v);
    t[x].lazy = 1;
    t[x].k = v;
    return;
  }
  push(x);
  int m = (r + l) / 2;
  update(ql, qr, v, x * 2 + 1, l, m);
  update(ql, qr, v, x * 2 + 2, m, r);
  t[x] = t[x * 2 + 1] + t[x * 2 + 2];
}

node sum(int ql, int qr, int x = 0, int l = 0, int r = N) {
  if (l >= ql && r <= qr)
    return t[x];
  if (qr <= l || ql >= r)
    return {0, 0};
  int m = (r + l) / 2;
  push(x);
  return sum(ql, qr, x * 2 + 1, l, m) + sum(ql, qr, x * 2 + 2, m, r);
}

int a[N];
pair<pii, pii> ops[N];
int main() {
  cin >> n;
  build();
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    C = max(C, a[i] + 1);
  }

  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int q, l, r, k;
    cin >> q >> l >> r >> k;
    ops[i] = {{q, l}, {r, k}};
    C = max(C, k + 1);
  }
  C += ~C & 1;

  p[0] = 1;
  for (int i = 1; i <= n; i++)
    p[i] = (1ll * p[i - 1] * C) % mod;
  pp[0] = 0;
  for (int i = 0; i <= n; i++)
    pp[i + 1] = (pp[i] + p[i]) % mod;

  for (int i = 0; i < n; i++)
    update(i, i + 1, a[i]);
  for (int z = 0; z < m; z++) {
    auto [q, l] = ops[z].first;
    auto [r, k] = ops[z].second;
    l--, r--;
    if (q == 0) {
      update(l, r + 1, k);
    } else {
      assert(q == 1);
      int answ = sum(l, l + k) == sum(r, r + k);
      cout << "-+"[answ];
    }
  }
}
