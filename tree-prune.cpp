// semenInRussia 2024
#include <iostream>
#include <vector>
using namespace std;

const int N = 1e6;
int sum[N], depth[N];
int dist[N]; // distance to leaf
vector<int> g[N];

int b[N];

int n;

void dfs(int x, int p = -1) {
  dist[x] = depth[x] = p == -1 ? 0 : depth[p] + 1;
  sum[x] = 1;
  for (int y : g[x]) {
    if (y != p) {
      dfs(y, x);
      sum[x] += sum[y];
      dist[x] = max(dist[y], dist[x]);
    }
  }
  int i = depth[x];
  b[i] += sum[x] - 1;
  b[i + 1] -= sum[x] - 1;

  int j = dist[x];
  b[j + 1] += 1;
}

void solve() {
  cin >> n;

  for (int x = 0; x < n; x++) {
    g[x].clear();
  }

  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  for (int i = 0; i <= n; i++) {
    b[i] = 0;
  }

  dfs(0);
  int ans = n + 1;
  int cur = 0;
  for (int i = 0; i <= n; i++) {
    cur += b[i];
    ans = min(ans, cur);
  }
  cout << ans << '\n';
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
