// semenInRussia 2024
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int N = 2e5 + 100;
const int inf = 1e9 + 6;
vector<int> g[N];

int dist[N][2];
int prv[N][2];

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  //--

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  for (int i = 0; i < n; i++) {
    dist[i][0] = dist[i][1] = +inf;
  }

  queue<pair<int, bool>> q;
  q.push({0, 1});
  dist[0][1] = 1;
  while (!q.empty()) {
    auto [x, o] = q.front();
    q.pop();
    for (int y : g[x]) {
      auto op = dist[x][o] + 1;
      if (op < dist[y][!o]) {
        q.push({y, !o});
        prv[y][!o] = x;
        dist[y][!o] = op;
      }
    }
  }

  int x = n - 1;
  int o = 1;
  if (dist[n - 1][1] > 3 * n + 2) {
    o = 0;
  }

  int t = dist[x][o];

  vector<int> path = {};
  int cnt = 1;
  while (cnt < t) {
    cnt++;
    x = prv[x][o];
    o = !o;
    path.push_back(x);
  }

  cout << (~t & 1) << " " << t << "\n";
  reverse(path.begin(), path.end());
  o = 1;
  for (int x : path) {
    cout << (x + 1) << (o ? " + " : " - ");
    o = !o;
  }
  cout << n;
}
