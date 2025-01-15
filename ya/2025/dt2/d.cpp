// semenInRussia 2025
#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

const int N = 2e5 + 1000;
vector<int> g[N];

map<pair<int, int>, int64_t> _w;

int64_t &w(int x, int y) {
  if (x > y) {
    swap(x, y);
  }
  return _w[{x, y}];
}

int64_t f[N], v[N];

int ti = 0;

const int L = 20;

int tin[N], tout[N];
int up[N][L];

int64_t optp[N];

void dfs0(int x, int fa = 0) {
  tin[x] = ti++;

  up[x][0] = fa;
  for (int j = 0; j + 1 < L; j++) {
    up[x][j + 1] = up[up[x][j]][j];
  }

  for (int y : g[x]) {
    if (y != fa) {
      dfs0(y, x);
    }
  }

  tout[x] = ti++;
}

bool par(int x, int y) { return tin[x] <= tin[y] && tin[y] <= tout[x]; }

int prelca(int x, int y) {
  for (int j = L - 1; j >= 0; j--) {
    int z = up[x][j];
    if (!par(z, y)) {
      x = z;
    }
  }
  return x;
}

int lca(int x, int y) {
  if (par(x, y)) {
    return x;
  }
  if (par(y, x)) {
    return y;
  }
  return up[prelca(x, y)][0];
}

using pii = pair<int, int>;

vector<pair<pii, int64_t>> opt[N];

int64_t ans[N], val[N];

void dfs2(int x, int p) {
  vector<int64_t> h;

  for (int y : g[x]) {
    if (y == p) {
      continue;
    }

    dfs2(y, x);
    f[x] += f[y];
    v[x] += v[y];
    h.push_back(f[y] + optp[y]);
  }

  sort(h.rbegin(), h.rend());

  ans[x] = 0;
  if (!h.empty()) {
    ans[x] += h[0];
  }
  if ((int)h.size() > 1) {
    ans[x] += h[1];
  }

  for (auto [ab, c] : opt[x]) {
    auto [a, b] = ab;
    if (b != -1) {
      ans[x] = max(ans[x], f[a] + f[b] + optp[a] + optp[b] + c);
    }
    f[x] += c;
  }
}

int64_t sp(int x) {
  int64_t s = 0;

  for (auto [ab, c] : _w) {
    auto [a, b] = ab;
    if (!par(x, a) && !par(x, b)) {
      s += c;
    }
  }

  return s;
}

void dfs3(int x, int64_t Sp, int p) {
  ans[x] = max(ans[x], Sp + val[x]);

  for (int y : g[x]) {
    if (y != p) {
      ans[x] = max(ans[x], Sp + val[x] + v[y] + f[y]);
    }
  }

  for (int y : g[x]) {
    if (y != p) {
      dfs3(y, sp(y), x);
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  for (int j = 0; j < m; j++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    w(a, b) += c;
  }

  dfs0(0);

  for (auto [xy, c] : _w) {
    auto [x, y] = xy;
    int z = lca(x, y);
    if (x == z || y == z) {
      if (x == z) {
        swap(x, y);
      }
      assert(x != y);
      int xp = prelca(x, y);
      opt[z].push_back({{xp, -1}, c});
      optp[xp] += c;
      v[x] += c;
      v[z] -= c;
      val[x] += c;
    } else {
      int yp = prelca(y, x);
      int xp = prelca(x, y);
      opt[z].push_back({{xp, yp}, c});
      // optp[{z, yp}] += c;
      // optp[{z, xp}] += c;
      val[x] += c, val[y] += c;
      v[x] += c, v[y] += c;
      v[xp] -= c, v[yp] -= c;
    }
  }

  dfs2(0, 0);
  dfs3(0, 0, 0);

  for (int x = 0; x < n; x++) {
    cout << ans[x] << " ";
  }
}
