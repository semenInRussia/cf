// semenInRussia 2024
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#ifdef home
#include "C:/Users/hrams/cf/debug.h"
#else
#define debug(...) ;
#endif

const int N = 3e5, L = 21;
int up[N][L];
int h[N];
int tin[N], tout[N];

vector<pair<int, int>> g[N];
int64_t b[N];

int ti = 0;

void dfs(int x, int fa = -1) {
  tin[x] = ti++;
  h[x] = fa == -1 ? 0 : h[fa] + 1;

  // build up[x]
  fill(up[x], up[x] + L, -1);
  up[x][0] = fa;
  for (int i = 0; i + 1 < L && up[x][i] != -1; i++) {
    up[x][i + 1] = up[up[x][i]][i];
  }

  for (auto [y, w] : g[x]) {
    if (y != fa) {
      b[y] = b[x] + w;
      dfs(y, x);
    }
  }

  tout[x] = ti++;
}

int p(int x, int y) { // return y in x
  return tin[x] <= tin[y] && tin[y] <= tout[x];
}

int lca(int x, int y) {
  if (p(x, y)) {
    return x;
  }
  if (p(y, x)) {
    return y;
  }
  for (int j = L - 1; j >= 0; j--) {
    if (up[x][j] == -1) {
      continue;
    }
    if (!p(up[x][j], y)) {
      x = up[x][j];
    }
  }
  return up[x][0];
}

int a1, b1;

const int64_t inf = 1e18 + 1000;

int64_t dist(int x, int y) {
  int z = lca(x, y);
  if (p(z, a1) && p(z, b1) &&
      ((p(a1, x) && p(b1, x)) || (p(a1, y) && p(b1, y)))) {
    return +inf;
  }
  return b[x] - b[z] + b[y] - b[z];
}

// k'th ancestor of x or -1 if jump over root
int jump(int x, int k) {
  for (int j = L - 1; j >= 0 && x != -1; j--) {
    if ((k >> j) & 1) {
      x = up[x][j];
    }
  }

  return x;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n, s, t;
  cin >> n >> s >> t;
  s--, t--;

  for (int i = 1; i < n; i++) {
    int x, y, w;
    cin >> x >> y >> w;
    x--, y--;
    g[x].push_back({y, w});
    g[y].push_back({x, w});
  }

  ti = 0;
  dfs(0);

  int q;
  cin >> q;

  while (q--) {
    int a2, b2, w;
    cin >> a1 >> b1 >> a2 >> b2 >> w;
    a1--;
    a2--;
    b1--;
    b2--;

    // debug(dist(s, t), dist(s, a2), dist(b2, t), dist(s, b2), dist(a2, t));

    auto ans = min({dist(s, t), dist(s, a2) + dist(b2, t) + w,
                    dist(s, b2) + w + dist(a2, t)});
    if (ans == +inf) {
      ans = -1;
    }
    cout << ans << "\n";
  }
}
