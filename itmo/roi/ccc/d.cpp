// semenInRussia 2025
#pragma GCC optimize("O3,unroll-loops")
#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <vector>
#ifndef home
#pragma GCC target("avx2")
#endif

using namespace std;

const int N = 1 << 18;
vector<int> g[N];
int c[N];

int p[N];
int tin[N], tout[N];
int nxt[N], v[N * 2];

int ti = 0;
void dfs(int x, int fa = -1) {
  p[x] = fa;
  tin[x] = ti++;
  for (int y : g[x]) {
    if (y != fa) {
      dfs(y, x);
    }
  }
  tout[x] = ti;
}

vector<int> t[4 * N];

void build(int x = 0, int l = 0, int r = 2 * N) {
  if (r - l == 1) {
    t[x] = {v[l]};
    return;
  }

  int m = (l + r) / 2;
  build(2 * x + 1, l, m);
  build(2 * x + 2, m, r);
  merge(t[2 * x + 1].begin(), t[2 * x + 1].end(), //
        t[2 * x + 2].begin(), t[2 * x + 2].end(), //
        back_inserter(t[x]));
}

int qry(int ql, int qr, int x = 0, int l = 0, int r = 2 * N) {
  if (ql <= l && r <= qr) {
    // >=qr
    auto it = lower_bound(t[x].begin(), t[x].end(), qr);
    return t[x].end() - it;
  }

  if (ql >= r || qr <= l) {
    return 0;
  }

  int m = (l + r) / 2;
  return qry(ql, qr, 2 * x + 1, l, m) + qry(ql, qr, 2 * x + 2, m, r);
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  assert(m == n - 1);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
    --c[i];
  }
  for (int j = 0; j < m; j++) {
    int x, y;
    cin >> x >> y;
    --x;
    --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  dfs(0, -1);

  for (int i = 0; i < ti; i++) {
    v[tin[i] + ti] = v[tin[i]] = c[i];
  }
  for (int i = 0; i < n; i++) {
    nxt[i] = 2 * ti;
  }

  for (int i = 2 * ti - 1; i >= 0; i--) {
    int x = v[i];
    v[i] = nxt[x];
    nxt[x] = i;
  }

  build();

  for (int x = 0; x < n; x++) {
    int64_t s = 0;
    for (int y : g[x]) {
      if (y != p[x]) {
        auto p = qry(tin[y], tout[y]);
        s += 1ll * p * p;
      }
    }
    // all outside tin[x]; tout[x]
    auto p = qry(tout[x], ti + tin[x]);
    s += 1ll * p * p;
    cout << s << " ";
  }
}
