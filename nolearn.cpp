// semenInRussia 2024
// https://codeforces.com/problemset/problem/1986/F
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int maxn = 3e5;
vector<int> g[maxn];
int h[maxn], d[maxn], s[maxn], r[maxn], n;
bool used[maxn];
vector<int> bs;

void dfs(int v, int p) {
  d[v] = h[v] = (p == -1) ? 0 : h[p] + 1;
  s[v] = 1;
  used[v] = true;
  for (int u : g[v]) {
    if (u == v || u == p)
      continue;
    if (used[u]) {
      d[v] = min(d[v], h[u]);
    } else {
      dfs(u, v);
      d[v] = min(d[v], d[u]);
      s[v] += s[u];
      if (d[u] > h[v])
        bs.push_back(u);
    }
  }
  r[v] = n - s[v];
}

void solve() {
  int m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    g[i].clear(), used[i] = 0;
  bs.clear();
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  ll all = 0;
  dfs(0, -1);
  for (int i = 0; i < s[0]; i++)
    all += i;
  ll ans = all;
  for (auto b : bs)
    ans = min(ans, all - 1ll * r[b] * s[b]);
  cout << ans << '\n';
}

int main() {
  int tt;
  cin >> tt;
  while (tt--)
    solve();
}
