// semenInRussia 2024
// https://cses.fi/problemset/task/1671
#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using ll = long long;

const int N = 2e5;
const ll inf = 1e18;
vector<pair<int, int>> g[N];
ll d[N];

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    g[a].push_back({b, c});
  }

  // fill d[i] - distance from 0=>i
  //
  // algorithm Dijkstra
  priority_queue<pair<ll, int>> q;
  q.push({0, 0});
  for (int i = 1; i < n; i++) {
    d[i] = +inf;
    q.push({-d[i], i});
  }

  while (!q.empty()) {
    auto [dx, x] = q.top();
    dx = -dx;
    q.pop();
    if (dx != d[x]) {
      continue;
    }
    for (auto [y, c] : g[x]) {
      if (d[y] > d[x] + c) {
        d[y] = d[x] + c;
        q.push({-d[y], y});
      }
    }
  }

  for (int i = 0; i < n; i++) {
    cout << d[i] << ' ';
  }
}
