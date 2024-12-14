// semenInRussia 2024
// https://codeforces.com/contest/2042/problem/D
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

#define all(x) x.begin(), x.end()

using namespace std;

#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")

const int N = 2e5 + 100;
pair<int, int> p[N];

vector<int> t[N * 4], a[N];

int b[N];
int answ[N];

int u;

int id(int x) { return lower_bound(b, b + u, x) - b; }

// count over intervals at node
int dot(int x, int l, int r, int ql, int qr) {
  int c = t[x].end() - lower_bound(t[x].begin(), t[x].end(), qr);
  if (l <= ql && ql < r) {
    c--;
  }
  return c;
}

// find min prefix, that {q,v} >= c
int lef(int x, int l, int r, int q, int v, int c) {
  if (r - l == 1) {
    return b[l];
  }

  int m = (r + l) / 2;
  int a = dot(2 * x + 1, l, m, q, v);
  int b = dot(2 * x + 2, m, r, q, v);
  if (a >= c) {
    return lef(2 * x + 1, l, m, q, v, c);
  }
  return lef(2 * x + 2, m, r, q, v, c - a);
}

int rig(int x, int l, int r, int q, int v) {
  // return next who is bigger than v
  if (0 <= l && r <= q + 1) {
    auto it = lower_bound(t[x].begin(), t[x].end(), v);
    if (l <= q && q < r) {
      it++;
    }
    return it == t[x].end() ? 1e9 : *it;
  }

  if (l > q) {
    return 1e9;
  }

  int m = (r + l) / 2;
  return min(rig(2 * x + 1, l, m, q, v), rig(2 * x + 2, m, r, q, v));
}

void build(int x, int l, int r) {
  if (r - l == 1) {
    swap(t[x], a[l]);
    sort(t[x].begin(), t[x].end());
    return;
  }

  int m = (r + l) / 2;
  build(2 * x + 1, l, m);
  build(2 * x + 2, m, r);
  merge(all(t[2 * x + 1]), all(t[2 * x + 2]), back_inserter(t[x]));
}

// count on [0; q] >=v, but -1 (not count q, v)
int count(int x, int l, int r, int q, int v) {
  if (0 <= l && r <= q) {
    int c = t[x].end() - lower_bound(t[x].begin(), t[x].end(), v);
    return c;
  }

  if (l >= q || r <= 0) {
    return 0;
  }

  int m = (r + l) / 2;
  return count(2 * x + 1, l, m, q, v) + count(2 * x + 2, m, r, q, v);
}

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> p[i].first >> p[i].second;
  }

  for (int i = 0; i < n; i++) {
    b[i] = p[i].first;
  }

  b[n] = 1;
  b[n + 1] = 1e9;

  sort(b, b + n + 2);
  u = unique(b, b + n + 2) - b;

  for (int i = 0; i <= u; i++) {
    a[i].clear();
  }

  for (int i = 0; i <= 4 * u; i++) {
    t[i].clear();
  }

  for (int i = 0; i < n; i++) {
    auto [l, r] = p[i];
    a[id(l)].push_back(r);
  }

  build(0, 0, u);

  for (int i = 0; i < n; i++) {
    auto [l, r] = p[i];
    int ll = id(l);

    int c = count(0, 0, u, ll + 1, r) - 1;

    // cout << "c=" << c << "\n";

    if (c == 0) {
      // cout << "0\n";
      answ[i] = 0;
      continue;
    }

    int l2 = lef(0, 0, u, ll, r, c);
    int r2 = rig(0, 0, u, ll, r);

    // cout << "[ " << l2 << "; " << r2 << "]\n";

    // cout << "l2=" << l2 << "\n";
    answ[i] = l - l2 + r2 - r;
  }

  for (int i = 0; i < n; i++) {
    cout << answ[i] << "\n";
  }
  cout << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
