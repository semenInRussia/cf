// semenInRussia 2025
#include <cassert>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

const int N = 51;
const int M = 1e5 + 10;
int u[M], v[M];

const int T = 1 << 17;
vector<int> t[2 * T - 1];

int n;

vector<int> combine(vector<int> a, vector<int> b) {
  a.resize(n);
  b.resize(n);
  vector<int> c(n);

  for (int i = 0; i < n; i++) {
    c[i] = b[a[i]];
  }

  return c;
}

vector<int> zero;

void upd1(vector<int> &row, int j) {
  row = zero;
  row[v[j]] = u[j];
}

void upd(int i, int j, int x, int l, int r) {
  if (r - l == 1) {
    upd1(t[x], j);
    return;
  }

  int m = (l + r) / 2;
  if (i < m) {
    upd(i, j, 2 * x + 1, l, m);
  } else {
    upd(i, j, 2 * x + 2, m, r);
  }
  t[x] = combine(t[2 * x + 1], t[2 * x + 2]);
}

int sz;

void upd(int i, int j) { upd(i, j, 0, 0, sz); }

vector<int> qry(int ql, int qr, int x, int l, int r) {
  if (ql <= l && r <= qr) {
    return t[x];
  }
  if (ql >= r || qr <= l) {
    return zero;
  }

  int m = (l + r) / 2;
  return combine(qry(ql, qr, 2 * x + 1, l, m), qry(ql, qr, 2 * x + 2, m, r));
}

vector<int> qry(int ql, int qr) { return qry(ql, qr, 0, 0, sz); }

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int m;
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    cin >> v[i] >> u[i];
    v[i]--;
    u[i]--;
  }

  zero.resize(n);
  for (int i = 0; i < n; i++) {
    zero[i] = i;
  }

  int t;
  cin >> t;

  sz = 1;
  while (sz < t) {
    sz *= 2;
  }

  for (int i = 0; i < t; i++) {
    int x;
    cin >> x;
    x--;
    upd(i, x);
  }

  int q;
  cin >> q;

  while (q--) {
    int typ;
    cin >> typ;

    if (typ == 1) {
      int l, r, s;
      cin >> l >> r >> s;
      l--, s--;
      cout << (qry(l, r)[s] + 1) << "\n";
    } else {
      int i, k;
      cin >> i >> k;
      i--, k--;
      upd(i, k);
    }
  }
}
