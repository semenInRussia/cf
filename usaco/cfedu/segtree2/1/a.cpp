// semenInRussia 2024
#include <cassert>
#include <iostream>
using ll = long long;
using namespace std;

const int maxn = (1 << 18);
ll t[4 * maxn];

ll get(int k, int x = 0, int l = 0, int r = maxn) {
  if (r - l == 1)
    return t[x];
  int m = (r + l) / 2;
  if (k < m)
    return t[x] + get(k, x * 2 + 1, l, m);
  else
    return t[x] + get(k, x * 2 + 2, m, r);
}

void add(int lq, int rq, ll v, int x = 0, int l = 0, int r = maxn) {
  if (l >= rq || r <= lq)
    return;
  // [l; r) \in [lq; rq)
  if (l >= lq && r <= rq)
    t[x] += v;
  else {
    int m = (r + l) / 2;
    add(lq, rq, v, x * 2 + 1, l, m);
    add(lq, rq, v, x * 2 + 2, m, r);
  }
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
      add(l, r, v);
    } else {
      assert(typ == 2);
      int k;
      cin >> k;
      cout << get(k) << '\n';
    }
  }
}
