// semenInRussia 2024
// https://cses.fi/problemset/task/1195
#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;

const int N = 2e5;
const ll inf = 1e18 + 5;
using graph = vector<pair<int, int>>[N];
graph g, t;

template <typename T>
using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;

int n;
ll dist1[N], distn[N];

void dij(graph g, ll d[N], int s) {
  for (int x = 0; x < n; x++) {
    d[x] = +inf;
  }
  d[s] = 0;
  min_priority_queue<pair<ll, int>> q;
  for (int i = 0; i < n; i++) {
    q.push({d[i], i});
  }
  while (!q.empty() && q.top().first != +inf) {
    auto [dx, x] = q.top();
    q.pop();
    if (dx != d[x])
      continue;
    for (auto [y, c] : g[x]) {
      if (d[x] + c < d[y]) {
        d[y] = d[x] + c;
        q.push({d[y], y});
      }
    }
  }
}

int main() {
  int m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    g[a].push_back({b, c});
    t[b].push_back({a, c});
  }

  dij(g, dist1, 0);
  dij(t, distn, n - 1);

  ll ans = +inf;
  for (int x = 0; x < n; x++) {
    for (auto [y, c] : g[x]) {
      ans = min(ans, dist1[x] + (c / 2) + distn[y]);
    }
  }
  cout << ans;
}
