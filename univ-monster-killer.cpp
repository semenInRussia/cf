// semenInRussia 2024
// https://codeforces.com/contest/1988/problem/D
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 4e5, B = 25;
const ll inf = LLONG_MAX;
ll a[N];
vector<int> g[N];
ll f[N][B];
ll p[B], s[B];
void dfs(int x, int fa = -1) {
  fill(f[x], f[x] + B, +inf);
  for (int i = 1; i < B; i++)
    f[x][i] = a[x] * i;
  for (int y : g[x]) {
    if (y == fa)
      continue;
    dfs(y, x);
    // suffix and prefix minimums on f[y]
    s[B - 1] = p[0] = +inf;
    for (int i = 0; i + 1 < B; i++)
      p[i + 1] = min(p[i], f[y][i]);
    for (int i = B - 1; i > 0; i--)
      s[i - 1] = min(s[i], f[y][i]);
    for (int i = 1; i < B; i++)
      f[x][i] += min(s[i], p[i]);
  }
}

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i], g[i].clear();
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b), g[b].push_back(a);
  }
  dfs(0);
  cout << *min_element(f[0], f[0] + B) << '\n';
}
int main() {
  int T;
  cin >> T;
  while (T--)
    solve();
}
