// semenInRussia 2024
// https://codeforces.com/problemset/problem/2042/F
#include <algorithm>
#include <cstdint>
#include <iostream>
using namespace std;

const int64_t infll = 1e18 + 100;
const int inf = 1e9 + 100;

struct node {
  int l = -inf;
  int r = -inf;
  int64_t sum = -infll;
  int64_t suf = -infll;
  int64_t pref = -infll;
  int64_t ans = -infll;

  int64_t ans2 = -infll; // if use 2 segments
};

node operator*(node a, node b) {
  node c;
  c.l = a.l;
  c.r = b.r;
  c.sum = a.sum + b.sum;
  c.pref = max(a.pref, a.sum + b.pref + c.l);
  c.suf = max(a.suf, b.sum + a.suf + c.r);
  c.ans = max({a.ans, b.ans, c.suf + c.pref});
  return c;
}

const int N = 2e5 + 1000;

node t[2 * N];

node query(int ql, int qr, int x = 0, int l = 0, int r = N) {
  if (ql <= l && r <= qr) {
    return t[x];
  }
  if (l >= qr || r <= ql) {
    return {};
  }

  int m = (r + l) / 2;
  return query(ql, qr, 2 * x + 1, l, m) * query(ql, qr, 2 * x + 2, m, r);
}

void upd(int j, node v, int x = 0, int l = 0, int r = N) {
  if (r - l == 1) {
    t[x] = v;
    return;
  }

  int m = (r + l) / 2;
  if (j < m) {
    upd(j, v, 2 * x + 1, l, m);
  } else {
    upd(j, v, 2 * x + 2, m, r);
  }

  t[x] = t[2 * x + 1] * t[2 * x + 2];
}

node one(int a, int b) {
  node c;
  c.l = b;
  c.r = b;
  c.sum = a;
  c.suf = a + b;
  c.pref = a + b;
}

int main() {
  int n;
  cin >> n;
}
