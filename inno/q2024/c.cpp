// semenInRussia 2024
#include <cstdint>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int N = 1e5 + 100;
vector<pair<int, pair<int, int>>> g[N];

const int B = 30;
int64_t dist[N][61];

const int64_t inf = 1e18 + 8;

template <typename T> using min_qu = priority_queue<T, vector<T>, greater<T>>;

void solve() {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    g[i].clear();
  }

  for (int i = 0; i < m; i++) {
    int x, y, l, dt;
    cin >> x >> y >> l >> dt;
    x--, y--;
    g[x].push_back({y, {l, dt}});
  }

  for (int x = 0; x < n; x++) {
    for (int i = -30; i <= +30; i++) {
      dist[x][i + B] = +inf;
    }
  }

  dist[0][0 + B] = 0;

  min_qu<pair<int64_t, pair<int, int>>> q;
  q.push({0, {0, 0}});

  while (!q.empty()) {
    auto [dx, ii] = q.top();
    auto [x, t] = ii;
    q.pop();

    if (dx != dist[x][t + B]) {
      continue;
    }

    for (auto [y, ii] : g[x]) {
      auto [l, dt] = ii;
      if (dt + t < -30 || dt + t > +30) {
        continue;
      }
      auto op = dist[x][t + B] + l;
      if (op < dist[y][t + dt + B]) {
        dist[y][t + dt + B] = op;
        q.push({op, {y, dt + t}});
      }
    }
  }

  int64_t ans = +inf;
  for (int t = -30; t <= +30; t++) {
    ans = min(ans, dist[n - 1][t + B]);
  }

  cout << (ans == +inf ? -1ll : ans) << "\n";
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
