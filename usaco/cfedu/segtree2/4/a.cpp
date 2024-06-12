// semenInRussia 2024
#include <iostream>
using namespace std;
using ll = long long;

const int maxn = (1 << 20);
ll t[2 * maxn], assign[2 * maxn] = {-1}, add[2 * maxn];

void push(int x, int l, int r) {
  if (r - l == 1)
    return;
  ll len = 1ll * (r - l) / 2;
  if (assign[x] > -1) {
    ll v = assign[x];
    assign[x] = -1;
    t[x * 2 + 1] = t[x * 2 + 2] = v * len;
    assign[x * 2 + 1] = assign[x * 2 + 2] = v;
    add[x * 2 + 1] = add[x * 2 + 2] = 0;
  }
  ll v = add[x];
  add[x] = 0;
  t[x * 2 + 1] += len * v, t[x * 2 + 2] += len * v;
  add[x * 2 + 1] += v, add[x * 2 + 2] += v;
}

ll query(int ql, int qr, int x = 0, int l = 0, int r = maxn) {
  if (ql >= r || qr <= l)
    return 0;
  if (l >= ql && r <= qr)
    return t[x];
  push(x, l, r);
  int m = (l + r) / 2;
  return query(ql, qr, x * 2 + 1, l, m) + query(ql, qr, x * 2 + 2, m, r);
}

// increment()
void increment(int ql, int qr, ll v, int x = 0, int l = 0, int r = maxn) {
  if (qr <= l || ql >= r)
    return;
  if (l >= ql && r <= qr) {
    add[x] += v;
    t[x] += v * (r - l);
    return;
  }
  push(x, l, r);
  int m = (r + l) / 2;
  increment(ql, qr, v, x * 2 + 1, l, m);
  increment(ql, qr, v, x * 2 + 2, m, r);
  t[x] = t[x * 2 + 1] + t[x * 2 + 2];
}

void change(int ql, int qr, ll v, int x = 0, int l = 0, int r = maxn) {
  if (qr <= l || ql >= r)
    return;
  if (l >= ql && r <= qr) {
    assign[x] = v;
    add[x] = 0;
    t[x] = v * (r - l);
    return;
  }
  push(x, l, r);
  int m = (r + l) / 2;
  change(ql, qr, v, x * 2 + 1, l, m);
  change(ql, qr, v, x * 2 + 2, m, r);
  t[x] = t[x * 2 + 1] + t[x * 2 + 2];
}

int main() {
  int n, m;
  cin >> n >> m;
  while (m--) {
    int typ;
    cin >> typ;
    if (typ == 1) {
      int l, r, v;
      cin >> l >> r >> v;
      change(l, r, ll(v));
    } else if (typ == 2) {
      int l, r, v;
      cin >> l >> r >> v;
      increment(l, r, ll(v));
    } else {
      int l, r;
      cin >> l >> r;
      cout << query(l, r) << '\n';
    }
  }
}
