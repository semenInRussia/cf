// Copyright 2024 semenInRussia
// CF https://codeforces.com/problemset/problem/118/E
// #graphs #dfs *2000

#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
using pii = pair<int, int>;

const int maxn = 1e5;
vector<int> g[maxn];
vector<pii> answ;
int h[maxn], d[maxn];
bool used[maxn], ok = true;

void dfs(int u, int p = -1) {
  used[u] = true;
  d[u] = h[u] = (p == -1) ? 0 : h[p] + 1;

  if (!ok)
    return;

  for (int v : g[u]) {
    if (v == p)
      continue;
    if (used[v]) { // back edge {u, v}
      d[u] = min(d[u], h[v]);
      if (h[v] > h[u])
        answ.push_back({v, u});
    } else { // span edge {u, v}
      answ.push_back({u, v});
      dfs(v, u);
      d[u] = min(d[u], d[v]);
      if (d[v] > h[u])
        ok = false; // this is bridge..
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b), g[b].push_back(a);
  }

  dfs(0);
  if (accumulate(used, used + n, 0) != n) // 2+ components
    ok = false;

  if (!ok)
    answ.clear();
  for (auto [a, b] : answ)
    cout << (a + 1) << ' ' << (b + 1) << '\n';
  cout << (ok ? "" : "0\n");
}
