// semenInRussia 2024
// https://cses.fi/problemset/task/1673
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using ll = long long;

const int N = 2e4;
const ll inf = 1e18 + 5;
vector<pair<int, int>> g[N];
bool ch[N];

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
  for (int i = 0; i <= n; i++) {
    d[i] = -inf;
  }
  d[0] = 0;
  ll ans = -inf;
  for (int k = 0; k <= 2 * n; k++) {
    fill(ch, ch + n, 0);
    for (int x = 0; x < n; x++) {
      for (auto [y, c] : g[x]) {
        // d[y] = d[x] + c
        if (d[x] != -inf && d[y] < d[x] + c) {
          d[y] = d[x] + c;
          ch[y] = 1;
        }
      }
    }
    ans = d[n - 1];
  }
  queue<int> q;
  for (int i = 0; i < n; i++)
    if (ch[i])
      q.push(i);

  while (!q.empty()) {
    int x = q.front();
    q.pop();
    ch[x] = 1;
    for (auto [y, _] : g[x]) {
      if (!ch[y])
        q.push(y);
    }
  }

  if (ch[n - 1])
    cout << "-1";
  else
    cout << ans;
}
