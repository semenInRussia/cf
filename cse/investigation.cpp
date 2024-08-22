// semenInRussia 2024
// https://cses.fi/problemset/task/1202
#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using ll = long long;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

const int N = 2e5, mod = 1e9 + 7;
const ll inf = 1e18;
vector<pair<int, int>> g[N], t[N];

// f - flights, w - ways
int w[N];
int minf[N], maxf[N];

ll dist[N];
int main() {
  int n, m;
  cin >> n >> m;
  for (int j = 0; j < m; j++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    g[a].push_back({b, c});
    t[b].push_back({a, c});
  }

  // run Dijkstra
  for (int i = 0; i < n; i++) {
    dist[i] = +inf;
  }
  dist[0] = 0;
  min_heap<pair<ll, int>> q;
  // fill minf[] and other
  for (int i = 0; i < n; i++) {
    dist[i] = +inf;
    minf[i] = +1e9;
    maxf[i] = -1e9;
  }
  dist[0] = minf[0] = maxf[0] = 0;
  w[0] = 1;

  for (int i = 0; i < n; i++) {
    q.push({dist[i], i});
  }
  while (!q.empty() && q.top().first < +inf) {
    auto [dx, x] = q.top();
    q.pop();
    if (dx != dist[x]) {
      continue;
    }
    for (auto [y, c] : g[x]) {
      ll op = dist[x] + c;
      if (op < dist[y]) {
        dist[y] = op;
        q.push({op, y});
        minf[y] = minf[x] + 1;
        maxf[y] = maxf[x] + 1;
        w[y] = w[x];
      } else if (op == dist[y]) {
        minf[y] = min(minf[y], minf[x] + 1);
        maxf[y] = max(maxf[y], maxf[x] + 1);
        w[y] = (w[x] + w[y]) % mod;
      }
    }
  }
  //
  cout << dist[n - 1] << ' ';
  cout << w[n - 1] << ' ';
  cout << minf[n - 1] << ' ';
  cout << maxf[n - 1] << ' ';
}
