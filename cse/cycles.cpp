// semenInRussia 2024
// https://cses.fi/problemset/task/1195
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int N = 2e5;
const ll inf = 1e18 + 5;
vector<pair<int, int>> g[N];

ll d[N];
int fa[N];

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    g[a].push_back({b, c});
  }

  // Bellman-ford
  for (int x = 0; x < n; x++) {
    d[x] = +inf;
  }
  d[0] = 0;
  int ans = -1;
  for (int k = 0; k < n; k++) {
    ans = -1;
    for (int x = 0; x < n; x++) {
      for (auto [y, c] : g[x]) {
        // d[y] = d[x] + c
        if (d[x] + c < d[y]) {
          fa[y] = x;
          d[y] = d[x] + c;
          ans = y;
        }
      }
    }
  }

  if (ans == -1) {
    cout << "NO";
    return 0;
  }
  cout << "YES\n";
  for (int i = 0; i < n; i++) {
    ans = fa[ans];
  }
  int x = fa[ans];
  vector<int> path = {ans};
  while (x != ans) {
    path.push_back(x);
    x = fa[x];
  }
  path.push_back(ans);

  reverse(path.begin(), path.end());
  for (int x : path) {
    cout << (x + 1) << ' ';
  }
}
