// semenInRussia 2024
#include <iostream>
#include <vector>
using namespace std;
const int N = 1e5, C = 315, inf = 1e9, K = 18;

// tree properties:
vector<int> g[N];
int h[N], d[N];
bool red[N];

// for LCA in O(1):
int tin[N];
using pii = pair<int, int>;
pii e[2 * N];      // { height[x], x }
pii spe[2 * N][K]; // sparse table for e[]

int t = 0;
void dfs(int typ, int x, int p) {
  // `typ` is one of:
  // 1: recompute d[x] from children + tin[x]
  // 2: recompute d[x] from children
  // 3: recompute d[x] from parents
  if (typ == 1) {
    h[x] = (p == -1 ? 0 : h[p] + 1);
    tin[x] = t;
    e[t++] = {h[x], x};
  }
  if (typ <= 2) {
    d[x] = +inf;
    if (red[x])
      d[x] = 0;
  } else if (typ == 3 && p > -1) {
    d[x] = min(d[x], d[p] + 1);
  }
  for (int y : g[x]) {
    if (y != p) {
      dfs(typ, y, x);
      if (typ == 1)
        e[t++] = {h[x], x};
      if (typ <= 2)
        d[x] = min(d[x], d[y] + 1);
    }
  }
}

int dist(int x, int y) {
  if (tin[x] == tin[y])
    return 0;
  // find LCA
  if (tin[x] > tin[y])
    swap(x, y);
  int k = __lg(tin[y] - tin[x]);
  int lc = min(spe[tin[x]][k], spe[tin[y] - (1 << k)][k]).second;
  return h[x] - h[lc] + h[y] - h[lc];
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
  dfs(1, 0, -1);
  dfs(3, 0, -1);

  // build sparse table for e[...]
  for (int i = 0; i < t; i++)
    spe[i][0] = e[i];
  for (int k = 0; k < K; k++)
    for (int i = 0; i + (2 << k) <= t; i++)
      spe[i][k + 1] = min(spe[i][k], spe[i + (1 << k)][k]);

  vector<int> q;
  for (int i = 0; i < m; i++) {
    int t, v;
    cin >> t >> v;
    v--;
    if (t == 1) {
      red[v] = 1;
      q.push_back(v);
      if (q.size() >= C) {
        dfs(2, 0, -1);
        dfs(3, 0, -1);
        q.clear();
      }
    } else {
      int ans = d[v];
      for (auto u : q)
        ans = min(ans, dist(u, v));
      cout << ans << '\n';
    }
  }
}
