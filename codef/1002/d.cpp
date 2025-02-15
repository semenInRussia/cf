// semenInRussia 2025
#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <queue>
#include <vector>

#pragma GCC optimize("Ofast")

using namespace std;

const int N = 1005;
vector<int> g1[N], g2[N];

// 0 - no used
// 1 - in use
// 2 - used

int col[N][N];
bool cycle[N][N]; // can reach cycle of range where each edge cost 0

template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

void dfs(int v1, int v2) {
  col[v1][v2] = 1;

  for (int u1 : g1[v1]) {
    int u2 = u1;
    if (!binary_search(g2[v2].begin(), g2[v2].end(), u2)) {
      continue;
    }
    if (col[u1][u2] == 0) {
      dfs(u1, u2);
    }
    if (col[u1][u2] == 1 || cycle[u1][u2] == 1) {
      cycle[v1][v2] = 1;
    }
  }

  col[v1][v2] = 2;
}

int64_t dist[N][N];

void solve() {
  int n, s1, s2;
  cin >> n >> s1 >> s2;
  s1--;
  s2--;

  int expectd = 1;

  for (int z : {1, 2}) {
    (void)z;
    int m;
    cin >> m;

    expectd *= m;

    for (int i = 0; i < n; i++) {
      g1[i].clear();
    }

    while (m--) {
      int a, b;
      cin >> a >> b;
      a--, b--;
      g1[a].push_back(b);
      g1[b].push_back(a);
    }

    swap(g1, g2);
  }

  for (int i = 0; i < n; i++) {
    sort(g1[i].begin(), g1[i].end());
    sort(g2[i].begin(), g2[i].end());
  }

  const int64_t inf = 1e18 + 100;

  int64_t cnt = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      col[i][j] = 0;
      dist[i][j] = +inf;
      cycle[i][j] = 0;
      cnt += g1[i].size() * g2[j].size();
    }
  }

  // cerr << cnt << " " << expectd;
  assert(cnt == 4 * expectd);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (col[i][j] == 0) {
        dfs(i, j);
      }
    }
  }

  min_heap<pair<int64_t, pair<int, int>>> q;
  q.push({0ll, {s1, s2}});
  dist[s1][s2] = 0;

  while (!q.empty()) {
    auto [dx, v] = q.top();
    auto [v1, v2] = v;
    q.pop();

    if (dx != dist[v1][v2]) {
      continue;
    }

    for (auto u1 : g1[v1]) {
      for (auto u2 : g2[v2]) {
        auto op = dist[v1][v2] + abs(u1 - u2);
        if (op < dist[u1][u2]) {
          dist[u1][u2] = op;
          q.push({op, {u1, u2}});
        }
      }
    }
  }

  int64_t ans = +inf;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (cycle[i][j]) {
        ans = min(ans, dist[i][j]);
      }
    }
  }

  if (ans == +inf) {
    ans = -1;
  }

  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int tt = 1;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
