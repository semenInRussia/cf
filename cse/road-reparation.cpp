// semenInRussia 2024
// https://cses.fi/problemset/task/1675
#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using ll = long long;

const int N = 2e5, inf = 1e9 + 5;
vector<pair<int, int>> g[N];
ll d[N];
bool used[N];

template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    g[a].push_back({b, c});
    g[b].push_back({a, c});
  }

  // check that only one component
  {
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
      int x = q.front();
      q.pop();
      if (used[x]) {
        continue;
      }
      used[x] = 1;
      for (auto [y, _] : g[x]) {
        q.push(y);
      }
    }

    bool ok = true;
    for (int i = 0; i < n && ok; i++) {
      if (!used[i]) {
        ok = false;
      }
    }

    if (!ok) {
      cout << "IMPOSSIBLE";
      return 0;
    }
    fill(used, used + n, 0);
  }

  // algorithm of Prim
  min_heap<pair<int, int>> q;
  // d[x] - is minimal edge from x to any vertex of the current tree
  for (int i = 0; i < n; i++) {
    d[i] = +inf;
  }
  for (auto [y, c] : g[0]) {
    d[y] = c;
    q.push({d[y], y});
  }

  ll ans = 0;
  used[0] = 1;
  while (!q.empty()) {
    auto [dx, x] = q.top();
    q.pop();
    if (used[x]) {
      continue;
    }
    used[x] = 1;
    ans += dx;
    for (auto [y, c] : g[x]) {
      if (c < d[y] && !used[y]) {
        d[y] = c;
        q.push({d[y], y});
      }
    }
  }

  cout << ans;
}
