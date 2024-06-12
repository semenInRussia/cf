// semenInRussia 2024
// https://codeforces.com/problemset/problem/1975/D
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using pii = pair<int, int>;
const int maxn = 2e5;
int n;
vector<int> g[maxn];

int dep[maxn], d[maxn], e[maxn], f[maxn];
void dfs(int v, int p) {
  d[v] = 0, f[v] = p;
  for (int u : g[v]) {
    if (u != p) {
      dfs(u, v);
      d[v] += d[u] + 1;
    }
  }
  e[v] = 0;
  int l = -1;
  for (int u : g[v])
    if (u != p)
      if (e[u] + 1 < e[v] || l == -1)
        l = u, e[v] = e[u] + 1;
  for (int u : g[v])
    if (u != p && u != l)
      e[v] += d[u] * 2 + 2;
}

void solve() {
  int a, b;
  cin >> n >> a >> b;
  a--, b--;
  for (int i = 0; i < maxn; i++)
    g[i].clear();
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    g[x].push_back(y), g[y].push_back(x);
  }
  dfs(a, -1);
  vector<int> t = {b};
  while (f[b] != -1)
    b = f[b], t.push_back(b);
  // t.pop_back();
  int x = t[(t.size() + 1) / 2];
  dfs(x, -1);
  cout << (t.size() + e[x]) << '\n';
}

int main() {
  int tt;
  cin >> tt;
  while (tt--)
    solve();
}
