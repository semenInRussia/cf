// semenInRussia 2024
// https://cses.fi/problemset/task/1645
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

const int N = 1 << 18;
int a[N], b[N], t[2 * N];

int qry(int ql, int qr, int x = 0, int l = 0, int r = N) { // max on [ql; qr)
  if (l >= ql && r <= qr)
    return t[x];
  if (l >= qr || r <= ql)
    return 0;
  int m = (r + l) / 2;
  return max(qry(ql, qr, 2 * x + 1, l, m), qry(ql, qr, 2 * x + 2, m, r));
}

void change(int i, int v, int x = 0, int l = 0, int r = N) {
  if (r - l == 1) {
    t[x] = v;
    return;
  }
  int m = (r + l) / 2;
  if (i < m)
    change(i, v, 2 * x + 1, l, m);
  else
    change(i, v, 2 * x + 2, m, r);
  t[x] = max(t[2 * x + 1], t[2 * x + 2]);
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }

  sort(b, b + n);
  int u = unique(b, b + n) - b;

  for (int i = 0; i < n; i++) {
    int j = lower_bound(b, b + u, a[i]) - b;
    cout << qry(0, j) << ' ';
    change(j, i + 1);
  }
}
