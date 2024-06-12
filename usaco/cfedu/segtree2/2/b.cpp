// semenInRussia 2024
#include <iostream>
using namespace std;
const int maxn = (1 << 4);
int lazy[2 * maxn], t[2 * maxn];
const int mod = 1e9 + 7;

void mult(int &a, int b) { a = (1ll * a * b) % mod; }
void add(int &a, int b) { a = (a + b) % mod; }

void push(int x, int l, int r) {
  if (lazy[x] > 1 && r - l > 1) {
    int v = lazy[x];
    lazy[x] = 1;
    mult(t[x * 2 + 1], v), mult(t[x * 2 + 2], v);
    mult(lazy[x * 2 + 1], v), mult(lazy[x * 2 + 2], v);
  }
}

void build(int x = 0, int l = 0, int r = maxn) {
  if (r - l == 1) {
    t[x] = 1;
    return;
  }
  int m = (r + l) / 2;
  build(x * 2 + 1, l, m);
  build(x * 2 + 2, m, r);
  t[x] = (t[x * 2 + 1] + t[x * 2 + 2]) % mod;
}

// change() - multiply
void change(int lq, int rq, int v, int x = 0, int l = 0, int r = maxn) {
  if (l >= rq || r <= lq)
    return;
  if (l >= lq && r <= rq) {
    mult(t[x], v);
    mult(lazy[x], v);
    return;
  }
  push(x, l, r);
  int m = (r + l) / 2;
  change(lq, rq, v, x * 2 + 1, l, m);
  change(lq, rq, v, x * 2 + 1, m, r);
  t[x] = (t[x * 2 + 1] + t[x * 2 + 1]) % mod;
}

int query(int lq, int rq, int x = 0, int l = 0, int r = maxn) {
  if (l >= rq || r <= lq)
    return 0;
  if (l >= lq && r <= rq)
    return t[x];
  push(x, l, r);
  int m = (r + l) / 2;
  int a = query(lq, rq, x * 2 + 1, l, m);
  int b = query(lq, rq, x * 2 + 2, m, r);
  return (a + b) % mod;
}

int main() {
  for (int i = 0; i < maxn; i++)
    lazy[i] = 1;
  build();
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int typ;
    cin >> typ;
    if (typ == 1) {
      int l, r, v;
      cin >> l >> r >> v;
      change(l, r, v);
    } else {
      int l, r;
      cin >> l >> r;
      cout << query(l, r) << '\n';
    }
  }
}
