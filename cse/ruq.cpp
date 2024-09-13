// semenInRussia 2024
// https://cses.fi/problemset/task/1651
#include <iostream>
using namespace std;
using ll = long long;

const int N = 1 << 18;
ll t[2 * N];

void update(int ql, int qr, int v, int x = 0, int l = 0, int r = N) {
  if (l >= qr || r <= ql) {
    return;
  }
  if (l >= ql && r <= qr) {
    t[x] += v;
    return;
  }
  int m = (r + l) / 2;
  update(ql, qr, v, 2 * x + 1, l, m);
  update(ql, qr, v, 2 * x + 2, m, r);
}

ll qry(int i, int x = 0, int l = 0, int r = N) {
  if (r - l == 1) {
    return t[x];
  }
  int m = (r + l) / 2;
  if (i < m) {
    return t[x] + qry(i, 2 * x + 1, l, m);
  }
  return t[x] + qry(i, 2 * x + 2, m, r);
}

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    update(i, i + 1, x);
  }

  for (int i = 0; i < m; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      int l, r, v;
      cin >> l >> r >> v;
      update(l - 1, r, v);
    } else {
      int i;
      cin >> i;
      cout << qry(i - 1) << '\n';
    }
  }
}
