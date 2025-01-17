// semenInRussia 2024
#include "tree.h"
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")

const int N = 5e5 + 100;
int h[N];

vector<int> g[N];

const int L = 18;
int up[N][L];
int tin[N], tout[N];

int ti = 0;

void dfs(int x, int fa = -1) {
  tin[x] = ti++;

  h[x] = fa == -1 ? 0 : h[fa] + 1;

  fill(up[x], up[x] + L, -1);
  up[x][0] = fa;
  for (int j = 0; up[x][j] != -1 && j + 1 < L; j++) {
    up[x][j + 1] = up[up[x][j]][j];
  }

  for (int y : g[x]) {
    if (y != fa) {
      dfs(y, x);
    }
  }

  tout[x] = ti++;
}

bool par(int x, int y) { return tin[x] <= tin[y] && tin[y] <= tout[x]; }

int lca(int x, int y) {
  if (par(x, y)) {
    return x;
  }
  if (par(y, x)) {
    return y;
  }

  for (int j = L - 1; j >= 0; j--) {
    int z = up[x][j];
    if (z != -1 && !par(z, y)) {
      x = z;
    }
  }

  return up[x][0];
}

// cont elements on segment
struct fenw {
  int sz;
  vector<unordered_map<int, int>> t;

  fenw() {}

  void resize(int n) {
    t.resize(n + 1);
    sz = n;
  }

  int pref(int r, int x) {
    int s = 0;
    for (; r > 0; r -= r & -r) {
      s += t[r][x];
    }
    return s;
  }

  inline int cnt(int x, int v) { return pref(tin[x] + 1, v); }

  void add1(int l, int x, int v) {
    l++;
    for (; l <= sz; l += l & -l) {
      t[l][x] += v;
    }
  }

  void add(int x, int h, int v) {
    int l = tin[x];
    int r = tout[x] + 1;
    add1(l, h, +v);
    add1(r, h, -v);
  }
};

fenw s1, s2;

void add(int x, vector<int> &a) {
  s1.add(x, a[x] + h[x], +1);
  s2.add(x, a[x] - h[x], +1);
}

void er(int x, vector<int> &a) {
  s1.add(x, a[x] + h[x], -1);
  s2.add(x, a[x] - h[x], -1);
}

vector<int> solve(int n, int q, vector<int> a, vector<int> p, vector<int> qt,
                  vector<int> qx, vector<int> qy) {
  int r = -1;

  for (int i = 0; i < n; i++) {
    if (p[i] == -1) {
      r = i;
      continue;
    }
    g[p[i]].push_back(i);
    g[i].push_back(p[i]);
  }

  dfs(r, -1);

  s1.resize(ti);
  s2.resize(ti);

  for (int x = 0; x < n; x++) {
    add(x, a);
  }

  vector<int> ans;
  ans.reserve(q);

  for (int i = 0; i < q; i++) {
    if (qt[i] == 2) {
      int x = qx[i];
      int y = qy[i];

      int z = lca(x, y);
      int t = h[x] - 2 * h[z];

      auto A = s1.cnt(x, h[x]) - s1.cnt(z, h[x]);
      auto B = s2.cnt(y, t) - s2.cnt(z, t);
      int cur = A + B;

      if (h[z] + a[z] == h[x]) {
        cur++;
      }

      ans.push_back(cur);
    } else {
      int x = qx[i];
      int v = qy[i];
      er(x, a);
      a[x] = v;
      add(x, a);
    }
  }

  return ans;
}

#ifdef home

int main() {
  int n, q;
  std::cin >> n >> q;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  std::vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> p[i];
  }
  std::vector<int> qt(q), qx(q), qy(q);
  for (int i = 0; i < q; ++i) {
    std::cin >> qt[i] >> qx[i] >> qy[i];
  }
  auto result = solve(n, q, a, p, qt, qx, qy);
  for (int x : result) {
    std::cout << x << "\n";
  }
  return 0;
}

#endif
