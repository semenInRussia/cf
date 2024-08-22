// semenInRussia 2024
// https://cses.fi/problemset/task/1196
#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;

template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

const int N = 2e5;
const ll inf = 1e18 + 5;
vector<pair<int, int>> g[N];
priority_queue<ll> d[N];

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    g[a].push_back({b, c});
  }

  min_heap<pair<ll, int>> q;
  d[0].push(0);
  q.push({0, 0});

  while (!q.empty()) {
    auto [dx, x] = q.top();
    q.pop();
    if (dx > d[x].top())
      continue;
    for (auto [y, c] : g[x]) {
      ll dy = dx + c;
      if (d[y].size() < k) {
        d[y].push(dy);
        q.push({dy, y});
      } else if (d[y].top() > dy) {
        d[y].pop();
        d[y].push(dy);
        q.push({dy, y});
      }
    }
  }

  vector<ll> ans;
  while (!d[n - 1].empty()) {
    ans.push_back(d[n - 1].top());
    d[n - 1].pop();
  }
  reverse(ans.begin(), ans.end());
  for (ll x : ans) {
    cout << x << ' ';
  }
}
