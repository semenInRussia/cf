// semenInRussia 2024
// https://cses.fi/problemset/task/2166
#include <iostream>
using namespace std;
using ll = long long;

struct node {
  ll max = 0;
  ll sum = 0;
};

inline node combine(node a, node b) {
  return {max(a.max, b.max + a.sum), a.sum + b.sum};
}

const int N = 1 << 18;
node t[2 * N];

node query(int ql, int qr, int x = 0, int l = 0, int r = N) {
  if (l >= ql && r <= qr) {
    return t[x];
  }
  if (l >= qr || r <= ql) {
    return {0, 0};
  }
  int m = (r + l) / 2;
  return combine(query(ql, qr, 2 * x + 1, l, m), //
                 query(ql, qr, 2 * x + 2, m, r));
}

void update(int i, int v, int x = 0, int l = 0, int r = N) {
  if (r - l == 1) {
    t[x] = {max(0, v), v};
    return;
  }
  int m = (r + l) / 2;
  if (i < m) {
    update(i, v, 2 * x + 1, l, m);
  } else {
    update(i, v, 2 * x + 2, m, r);
  }
  t[x] = combine(t[2 * x + 1], t[2 * x + 2]);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    update(i, x);
  }
  for (int i = 0; i < q; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      int i, v;
      cin >> i >> v;
      update(i - 1, v);
    } else {
      int l, r;
      cin >> l >> r;
      cout << query(l - 1, r).max << '\n';
    }
  }
}
