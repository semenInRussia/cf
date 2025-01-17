// semenInRussia 2025
#include <algorithm>
#include <cstdint>
#include <iostream>

#include <queue>
#include <vector>

using namespace std;

const int inf = 1e9 + 5;

vector<vector<int>> dist;
vector<vector<int>> f;
vector<string> t;

vector<pair<int, int>> neigh(pair<int, int> x) {
  auto [i, j] = x;
  return {{i + 1, j}, {i - 1, j}, {i, j + 1}, {i, j - 1}};
}

int main() {
  int n, m;
  cin >> n >> m;
  t.resize(n);
  for (auto &row : t) {
    cin >> row;
  }

  dist.resize(n);
  f.resize(n);

  for (auto &row : f) {
    row.resize(m);
    fill(row.begin(), row.end(), -inf);
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (t[i][j] != 'H') {
        continue;
      }

      for (auto &row : dist) {
        row.resize(m);
        fill(row.begin(), row.end(), +inf);
      }

      queue<pair<int, int>> q;
      q.push({i, j});
      dist[i][j] = 0;

      while (!q.empty()) {
        auto x = q.front();
        q.pop();

        for (auto [di, dj] : neigh(x)) {
          if (di < 0 || dj < 0 || di == n || dj == m || t[di][dj] == 'F') {
            continue;
          }
          int op = dist[x.first][x.second] + 1;
          if (dist[di][dj] > op) {
            q.push({di, dj});
            dist[di][dj] = op;
          }
        }
      }

      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          f[i][j] = max(f[i][j], dist[i][j]);
        }
      }
    }
  }

  int mn = +inf;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      mn = min(f[i][j], mn);
    }
  }

  vector<pair<int, int>> ans;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (f[i][j] == mn) {
        ans.emplace_back((i + 1), (j + 1));
      }
    }
  }

  cout << ans.size() << "\n";
  for (auto [x, y] : ans) {
    cout << x << " " << y << "\n";
  }
}
