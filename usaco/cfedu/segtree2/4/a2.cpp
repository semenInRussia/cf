// semenInRussia 2024
#include <iostream>
using namespace std;
const int N = 1 << 20;
using ll = long long;
int assign[2 * N] = {-1};
ll t[2 * N], add[2 * N];

void push(int x, int len) {
  if (len == 1)
    return;
  if (assign[x] != -1) {
    t[x * 2 + 1] = t[x * 2 + 2] = 1ll * (len / 2) * assign[x];
    assign[x * 2 + 1] = assign[x * 2 + 2] = assign[x];
    add[x * 2 + 1] = add[x * 2 + 2] = 0;
    assign[x] = -1;
  }
  if (add[x]) {
    t[x * 2 + 1] += add[x] * (len / 2);
    t[x * 2 + 2] += add[x] * (len / 2);
    add[x * 2 + 1] += add[x];
    add[x * 2 + 2] += add[x];
    add[x] = 0;
  }
}

ll qry(int ql, int qr, int x = 0, int l = 0, int r = N) {
  if (l >= ql && r <= qr)
    return t[x];
  if (l >= qr || r <= ql)
    return 0;
  push(x, r - l);
  int m = (r + l) / 2;
  return qry(ql, qr, x * 2 + 1, l, m) + qry(ql, qr, x * 2 + 2, m, r);
}

void change(int ql, int qr, ll v, int x = 0, int l = 0, int r = N) {
  if (l >= ql && r <= qr) {
    assign[x] = v;
    t[x] = v * (r - l);
    add[x] = 0;
    return;
  }
  if (l >= qr || r <= ql)
    return;
  push(x, r - l);
  int m = (r + l) / 2;
  change(ql, qr, v, x * 2 + 1, l, m);
  change(ql, qr, v, x * 2 + 2, m, r);
  t[x] = t[x * 2 + 1] + t[x * 2 + 2];
}

void inc(int ql, int qr, int v, int x = 0, int l = 0, int r = N) {
  if (l >= ql && r <= qr) {
    add[x] += v;
    t[x] += 1ll * v * (r - l);
    return;
  }
  if (l >= qr || r <= ql)
    return;
  push(x, r - l);
  int m = (r + l) / 2;
  inc(ql, qr, v, x * 2 + 1, l, m);
  inc(ql, qr, v, x * 2 + 2, m, r);
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
      inc(l, r, ll(v));
    } else {
      int l, r;
      cin >> l >> r;
      cout << qry(l, r) << '\n';
    }
  }
}
