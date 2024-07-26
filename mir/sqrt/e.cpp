// semenInRussia 202
#include <iostream>
#include <queue>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,fma,bmi2,tune=native")
using namespace std;
using pii = pair<int, int>;
const int N = 1e5, C = 315, inf = N, K = 17;

// tree properties:
vector<int> g[N];
int h[N], d[N], red[N];

// for LCA in O(1):
int tin[N];
pii e[2 * N];      // { height[x], x }
pii spe[K][2 * N]; // sparse table for `e`

int t = 0;
void dfs(int x, int p = -1) {
  h[x] = (p == -1 ? 0 : h[p] + 1);
  tin[x] = t;
  e[t++] = {h[x], x};
  for (int y : g[x]) {
    if (y != p) {
      dfs(y, x);
      e[t++] = {h[x], x};
    }
  }
}
int dist(int x, int y) {
  // find LCA
  int l = tin[x], r = tin[y];
  if (l > r)
    swap(l, r);
  if (r == l)
    return 0;
  int k = __lg(r - l);
  int lc = min(spe[k][l], spe[k][r - (1 << k)]).second;
  return h[x] - (h[lc] * 2) + h[y];
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  red[0] = 1;
  dfs(0, -1);
  for (int x = 0; x < n; x++)
    d[x] = h[x];

  // build sparse table for e[...]
  swap(spe[0], e);
  for (int k = 0; k < K; k++)
    for (int i = 0; i + (2 << k) <= t; i++)
      spe[k + 1][i] = min(spe[k][i], spe[k][i + (1 << k)]);

  vector<int> ops;
  ops.reserve(C);
  for (int i = 0; i < m; i++) {
    int t, x;
    cin >> t >> x;
    x--;
    if (t == 1) {
      red[x] = 1;
      d[x] = 0;
      ops.push_back(x);
      if (ops.size() == C) {
        queue<int> q;
        for (int x : ops)
          q.push(x);
        ops.clear();
        // bfs
        while (!q.empty()) {
          int x = q.front();
          q.pop();
          for (int y : g[x])
            if (d[x] + 1 < d[y])
              d[y] = d[x] + 1, q.push(y);
        }
      }
    } else {
      int ans = d[x];
      for (auto u : ops)
        ans = min(ans, dist(u, x));
      cout << ans << '\n';
    }
  }
}
