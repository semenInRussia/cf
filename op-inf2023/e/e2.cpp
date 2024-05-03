// Copyright 2024 semenInRussia

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct edge {
  size_t u;
  size_t v;
  size_t col;
};

struct vert {
  size_t col;
  size_t v;
};

bool check(size_t u, size_t n, size_t k, vector<vector<size_t>> &g,
           vector<vector<size_t>> &c, vector<bool> &visited, vector<bool> &seen,
           size_t path_len) {

#ifdef TEST
  cout << "check (" << u << ", " << n << ", " << k << ", [";
  for (auto x : visited) {
    cout << x << ' ';
  }
  cout << "], [ ";
  for (auto s : seen) {
    cout << s << ' ';
  }
  cout << "], " << path_len << ")" << endl;
#endif

  visited[u] = true;

  size_t cols_used = 0;

  for (auto s : seen) {
    cols_used += s;
  }

  if (n - path_len < (k - cols_used)) {
    return false;
  }

  if (path_len == n) {
    return true;
  }

  for (size_t vi = 0; vi < g[u].size(); vi++) {
    size_t v = g[u][vi];

    if (visited[v]) {
      continue;
    }

    size_t col = c[u][vi];
    bool old = seen[col];
    seen[col] = true;

    if (check(v, n, k, g, c, visited, seen, path_len + 1)) {
      return true;
    }

    seen[col] = old;
  }

  return false;
}

bool check(size_t n, size_t k, vector<vector<size_t>> &g,
           vector<vector<size_t>> &c) {
  vector<bool> visited(n + 1, false);
  vector<bool> seen(k + 1, false);

  // for (size_t u = 1; u <= n; u++) {
  //   fill(visited.begin(), visited.end(), false);
  //   fill(seen.begin(), seen.end(), false);
  if (check(2, n, k, g, c, visited, seen, 1))
    return true;
  // }

  return false;
}

int main() {
  size_t n, m, k;
  cin >> n >> m >> k;

  // O(m)

  vector<edge> e(m + 1);
  vector<vector<size_t>> g(n + 1);
  vector<vector<size_t>> c(n + 1);

  for (size_t i = 1; i <= m; i++) {
    cin >> e[i].u >> e[i].v >> e[i].col;
    g[e[i].u].push_back(e[i].v);
    c[e[i].u].push_back(e[i].col);

    g[e[i].v].push_back(e[i].u);
    c[e[i].v].push_back(e[i].col);
  }

  size_t q;
  cin >> q;

  // O(q)
  while (q--) {
    size_t i;
    cin >> i;
    cin >> e[i].col;

    auto [u, v, col] = e[i];

    size_t col_i = distance(g[u].begin(), find(g[u].begin(), g[u].end(), v));
    c[u][col_i] = col;

    col_i = distance(g[v].begin(), find(g[v].begin(), g[v].end(), u));
    c[v][col_i] = col;

    if (check(n, k, g, c)) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }

  return 0;
}
