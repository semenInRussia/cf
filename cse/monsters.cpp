// semenInRussia 2024
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int N = 1005, inf = 1e9 + 5;
using pii = pair<int, int>;

string t[N];
int n, m;

vector<pii> adj(pii x) {
  vector<pii> q;
  for (int z : {-1, +1}) {
    auto [i, j] = x;
    if (i + z < n && i + z >= 0)
      q.push_back({i + z, j});
    if (j + z < m && j + z >= 0)
      q.push_back({i, j + z});
  }
  return q;
}

template <typename T> struct arr {
  T a[N][N];
  T &operator[](pii p) { return a[p.first][p.second]; }
};

arr<bool> used;
arr<pii> prv;
arr<int> kill, dist;

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }
  pii beg = {-1, -1};
  queue<pii> q;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      kill[{i, j}] = dist[{i, j}] = +inf;
      if (t[i][j] == 'A') {
        beg = {i, j};
      } else if (t[i][j] == 'M') {
        q.push({i, j});
        kill[{i, j}] = 0;
      }
    }
  }

  // for every monsters
  while (!q.empty()) {
    auto x = q.front();
    q.pop();
    for (auto y : adj(x)) {
      if (t[y.first][y.second] == '#')
        continue;
      if (kill[x] + 1 < kill[y]) {
        kill[y] = kill[x] + 1;
        q.push(y);
      }
    }
  }

  // find dist[] = distance from A
  dist[beg] = 0;
  q.push(beg);
  while (!q.empty()) {
    auto x = q.front();
    q.pop();
    for (auto y : adj(x)) {
      if (t[y.first][y.second] == '#')
        continue;
      if (dist[x] + 1 < dist[y]) {
        dist[y] = dist[x] + 1;
        prv[y] = x;
        q.push(y);
      }
    }
  }

  // check boundary cells
  bool ok = 0;
  pii e = {-1, -1};
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      bool bound = i == n - 1 || j == m - 1 || i == 0 || j == 0;
      if (bound && dist[{i, j}] < kill[{i, j}]) {
        ok = 1;
        e = {i, j};
        break;
      }
    }
  }

  cout << (ok ? "YES\n" : "NO");
  if (!ok) {
    return 0;
  }
  pii cur = e;
  string path;
  while (cur != beg) {
    pii p = prv[cur];
    if (cur.first != p.first)
      path += "UD"[cur.first > p.first];
    if (cur.second != p.second)
      path += "LR"[cur.second > p.second];
    cur = prv[cur];
  }
  reverse(path.begin(), path.end());
  cout << path.size() << '\n';
  cout << path;
}
