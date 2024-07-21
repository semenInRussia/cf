// semenInRussia 2024
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int maxn = 5005;
vector<int> g[maxn];
int a[maxn], p[maxn];
int d[maxn], na[maxn];
bool ok[maxn];
void dfs(int v, int p = -1) {
  int L = 0;
  int chs = false;
  for (int u : g[v]) {
    if (u != p) {
      chs = true;
      dfs(u, v);
      L += a[u];
    }
  }
  ok[v] = 1;
  for (int u : g[v])
    if (u != p)
      ok[v] &= ok[u];
  if (ok[v]) {
    ok[v] = !chs || a[v] <= L;
    na[v] = chs ? min(L, a[v]) : a[v];
    d[v] = chs ? max(a[v] - L, 0) : 0;
    return;
  }
  d[v] = 0;
  L = 0;
  for (int u : g[v]) {
    if (u != p) {
      d[v] += d[u];
      L += na[u];
    }
  }
  if (a[v] <= L)
    na[v] = a[v];
  else
    na[v] = L, d[v] += a[v] - L;
}
void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i], ok[i] = 0, g[i].clear();
  for (int i = 1; i < n; i++) {
    cin >> p[i];
    p[i]--;
    g[p[i]].push_back(i);
  }
  dfs(0);
  cout << d[0] << '\n';
}

int main() {
  int tt;
  cin >> tt;
  while (tt--)
    solve();
}
