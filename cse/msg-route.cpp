// semenInRussia 2024
// https://cses.fi/problemset/task/1667
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int N = 2e5;
bool used[N];
int dist[N], prv[N];
vector<int> g[N];

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  queue<int> q;
  q.push(0);
  used[0] = 1;

  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int y : g[x]) {
      if (used[y])
        continue;
      used[y] = 1;
      dist[y] = dist[x] + 1;
      prv[y] = x;
      q.push(y);
    }
  }

  if (!used[n - 1]) {
    cout << "IMPOSSIBLE";
  } else {
    vector<int> path;
    int v = n - 1;
    while (v != 0) {
      path.push_back(v);
      v = prv[v];
    }
    path.push_back(0);
    reverse(path.begin(), path.end());
    cout << path.size() << '\n';
    for (int x : path) {
      cout << (x + 1) << ' ';
    }
  }
}
