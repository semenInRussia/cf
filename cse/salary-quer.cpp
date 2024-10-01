// semenInRussia 2024
// https://cses.fi/problemset/task/1144
#include <iostream>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")

const int R = 1 << 30, N = 2e5;
int a[N], out[N];

struct node {
  int l, r;
  node *left = 0, *right;
  int sum = 0;

  node() {}
  node(int _l, int _r) : l(_l), r(_r) {}

  void extend();

  int qry(int ql, int qr) {
    if (l >= ql && r <= qr) {
      return sum;
    }
    if (l >= qr || r <= ql) {
      return 0;
    }
    extend();
    return left->qry(ql, qr) + right->qry(ql, qr);
  }

  void inc(int s, int v) {
    if (r - l == 1) {
      sum += v;
      return;
    }

    extend();
    if (s < left->r) {
      left->inc(s, v);
    } else {
      right->inc(s, v);
    }
    sum = left->sum + right->sum;
  }
};

const int maxcnt = 50 * N;
node t[maxcnt];
int cnt = 0;
node *new_node(int l, int r) {
  if (cnt >= maxcnt) {
    return new node(l, r);
  }
  t[cnt].l = l;
  t[cnt].r = r;
  return &t[cnt++];
}

void node::extend() {
  if (left == 0) {
    int m = (r - l) / 2 + l;
    left = new_node(l, m);
    right = new_node(m, r);
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n, q;
  cin >> n >> q;
  node t(0, R);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    t.inc(a[i], +1);
  }
  for (int i = 0; i < q; i++) {
    char ch;
    cin >> ch;
    if (ch == '!') {
      int k, x;
      cin >> k >> x;
      int &p = a[k - 1];
      t.inc(p, -1);
      p = x;
      t.inc(x, +1);
    } else {
      int l, r;
      cin >> l >> r;
      cout << t.qry(l, r + 1) << '\n';
    }
  }
}
