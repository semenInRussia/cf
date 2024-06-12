// semenInRussia 2024
#include <climits>
#include <iostream>
using namespace std;
const int maxn = (1 << 20);
using ll = long long;
const ll inf = LLONG_MAX;
ll lazy[2 * maxn], t[2 * maxn];

void push(int x, int l, int r) {
  if (lazy[x] && r - l > 1) {
    ll v = lazy[x];
    lazy[x] = 0;
    t[x * 2 + 1] += v, t[x * 2 + 2] += v;
    lazy[x * 2 + 1] += v, lazy[x * 2 + 2] += v;
  }
}

void change(int lq, int rq, ll v, int x = 0, int l = 0, int r = maxn) {
  if (l >= rq || r <= lq)
    return;
  if (l >= lq && r <= rq) {
    lazy[x] += v, t[x] += v;
    return;
  }
  push(x, l, r);
  int m = (r + l) / 2;
  change(lq, rq, v, x * 2 + 1, l, m);
  change(lq, rq, v, x * 2 + 2, m, r);
  t[x] = min(t[x * 2 + 1], t[x * 2 + 2]);
}

ll query(int lq, int rq, int x = 0, int l = 0, int r = maxn) {
  if (lq >= r || l >= rq)
    return inf;
  if (l >= lq && r <= rq)
    return t[x];
  push(x, l, r);
  int m = (r + l) / 2;
  return min(query(lq, rq, x * 2 + 1, l, m), query(lq, rq, x * 2 + 2, m, r));
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
      change(l, r, v);
    } else {
      int l, r;
      cin >> l >> r;
      cout << query(l, r) << '\n';
    }
  }
}
