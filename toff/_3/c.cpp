// semenInRussia 2024
#include <cassert>
#include <iostream>
using namespace std;
using ll = long long;

#pragma GCC optimize("unroll-loops,Ofast")

const int N = 1 << 17;

struct node {
  int sum = 0;
  int lazy = -1;
};

node t[2 * N];

// push()
void upd(int x, int len, int val) {
  t[x].sum = len * val;
  t[x].lazy = val;
}

void push(int x, int len) {
  if (len == 1 || t[x].lazy == -1) {
    return;
  }
  int val = t[x].lazy;
  upd(2 * x + 1, len / 2, val);
  upd(2 * x + 2, len / 2, val);
  t[x].lazy = -1;
}

// assign(): range
void assign(int ql, int qr, int val, int x = 0, int l = 0, int r = N) {
  if (l >= ql && r <= qr) {
    upd(x, r - l, val);
    return;
  }
  if (l >= qr || r <= ql) {
    return;
  }
  int m = (r + l) / 2;
  push(x, r - l);
  assign(ql, qr, val, 2 * x + 1, l, m);
  assign(ql, qr, val, 2 * x + 2, m, r);
  t[x].sum = t[2 * x + 1].sum + t[2 * x + 2].sum;
}

// sum()
int sum(int ql, int qr, int x = 0, int l = 0, int r = N) {
  if (l >= ql && r <= qr) {
    return t[x].sum;
  }
  if (l >= qr || r <= ql) {
    return 0;
  }
  push(x, r - l);
  int m = (r + l) / 2;
  return sum(ql, qr, 2 * x + 1, l, m) + sum(ql, qr, 2 * x + 2, m, r);
}

// prv0()
int prv0(int i) {
  int sm = i - sum(0, i);

  int l = -2, r = i;
  while (r - l > 1) {
    int m = (r + l) / 2;

    bool ok = 0;
    if (m == -1) {
      ok = 1;
    }

    int z = m - sum(0, m);
    if (z < sm) {
      ok = 1;
    }

    if (ok) {
      l = m;
    } else {
      r = m;
    }
  }

  return l;
}

// nxt1()
int nxt1(int i) {
  int sm = sum(0, i + 1);

  int l = i, r = N;
  while (r - l > 1) {
    int m = (r + l) / 2;
    int z = sum(0, m + 1);
    if (z > sm) {
      r = m;
    } else {
      l = m;
    }
  }
  return r;
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int n;
  cin >> n;
  string s;
  cin >> s;

  int i;
  cin >> i;

  for (int i = 0; i < n; i++) {
    assign(i, i + 1, s[i] - '0');
  }

  // while k > 0;
  ll ans = 0;
  int k = t[0].sum;
  while (k > 0) {
    int c = sum(k - 1, k); // s[k-1]
    if (c == 0) {          // move forward
      int d = nxt1(k - 1);
      // 0001
      // 0123
      ans += d - (k - 1);
      assign(k - 1, d, 1);
      assert(t[0].sum == d + 1);
    } else {
      int d = prv0(k - 1); // if d=-1, all is ok
      ans += k - (d + 1);
      assign(d + 1, k, 0);
      assert(d + 1 == t[0].sum);
    }
    k = t[0].sum;
  }
  cout << ans;
}
