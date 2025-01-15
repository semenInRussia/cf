// semenInRussia 2025
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

const int N = 1e5 + 100;
vector<int> g[N];
int w[N], d[N];

int n, m, k;

map<int, int64_t> r[N], f[N], s[N];

bool bad[N];

const int inf = 1e9;

void dfs(int x, int fa = -1) {
  int64_t op = w[x];

  for (int y : g[x]) {
    if (y == fa) {
      continue;
    }
    dfs(y, x);
    for (auto [h, v] : r[y]) {
      r[x][h] += r[y][h];
    }
    op += r[y][d[x]];
  }

  r[x][+inf] = inf;

  if (bad[x]) {
    r[x][d[x]] = max(r[x][d[x]], op);
    for (auto j = d[x]; j != +inf; j = r[x].upper_bound(j)->first) {
      r[x][j] = max(r[x][j], op);
    }

    // for (int j = d[x]; j <= k; j++) {
    //   r[x][j] = max(r[x][j], op);
    // }
  }

  r[x].erase(inf);
}

void solve() {
  cin >> n >> m >> k;
  k += 5;
  for (int i = 1; i < n; i++) {
    int p;
    cin >> p;
    p--;
    g[p].push_back(i);
    g[i].push_back(p);
  }

  for (int i = 0; i < m; i++) {
    int v, d1, w1;
    cin >> v >> d1 >> w1;
    v--;
    bad[v] = true;
    w[v] = w1;
    d[v] = d1;
  }

  dfs(0);

  cout << r[0].rbegin()->second;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int tt = 1;
#ifdef home
  cin >> tt;
#endif

  while (tt--) {
    for (int i = 0; i < 1000; i++) {
      f[i].clear();
      g[i].clear();
      r[i].clear();
      s[i].clear();
      bad[i] = false;
    }
    solve();
    cout << "\n";
  }
}
