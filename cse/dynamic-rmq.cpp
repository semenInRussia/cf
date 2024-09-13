// semenInRussia 2024
// https://cses.fi/problemset/task/1649
#include <iostream>
using namespace std;

const int N = 1 << 18, inf = 1e9;
int t[2 * N];

void update(int i, int v, int x = 0, int l = 0, int r = N) {
  if (r - l == 1) {
    t[x] = v;
    return;
  }
  int m = (r + l) / 2;
  if (i < m) {
    update(i, v, 2 * x + 1, l, m);
  } else {
    update(i, v, 2 * x + 2, m, r);
  }
  t[x] = min(t[2 * x + 1], t[2 * x + 2]);
}

int qry(int ql, int qr, int x = 0, int l = 0, int r = N) {
  if (l >= qr || r <= ql) {
    return +inf;
  }
  if (l >= ql && r <= qr) {
    return t[x];
  }
  int m = (r + l) / 2;
  return min(qry(ql, qr, 2 * x + 1, l, m), qry(ql, qr, 2 * x + 2, m, r));
}

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    update(i, x);
  }
  for (int i = 0; i < m; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      int k, v;
      cin >> k >> v;
      update(k - 1, v);
    } else {
      int l, r;
      cin >> l >> r;
      cout << qry(l - 1, r) << '\n';
    }
  }
}
