// semenInRussia 2024
// https://cses.fi/problemset/task/1672
#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using ll = long long;

const int N = 510;
const ll inf = 1e18;
vector<pair<int, int>> g[N];
ll d[N][N];

int main() {
  int n, m, q;
  cin >> n >> m >> q;
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    g[a].push_back({b, c});
    g[b].push_back({a, c});
  }

  // fill d[i][j] - length of path i->j
  // algoirthm of Floyd-Warshall

  for (int x = 0; x < n; x++) {
    fill(d[x], d[x] + n, +inf);
    for (auto [y, c] : g[x]) {
      d[x][y] = min(d[x][y], 1ll * c);
    }
    d[x][x] = 0;
  }
  for (int k = 0; k < n; k++) {
    // add k
    for (int x = 0; x < n; x++)
      for (int y = 0; y < n; y++)
        if (d[x][k] != +inf && d[y][k] != +inf)
          d[x][y] = min(d[x][y], d[x][k] + d[y][k]);
  }

  // answer to queries
  for (int i = 0; i < q; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    if (a > b)
      swap(a, b);
    if (d[a][b] == +inf)
      d[a][b] = -1;
    cout << d[a][b] << '\n';
  }
}
