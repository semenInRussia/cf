// Copyright 2024 semenInRussia

#pragma GCC optimize("O3", "unroll-loops", )

#include <iostream>
#include <vector>

using namespace std;

int n, m;

inline bool at(vector<vector<bool>> &t, int i, int j) {
  return i < n && j < m && i >= 0 && j >= 0 && t[i][j];
}

int fill(vector<vector<bool>> &t) {
  int filled = 0;
#pragma GCC ivdep

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (t[i][j])
        continue;
      bool ok = at(t, i - 2, j - 1) || at(t, i - 1, j - 2) ||
                // +-
                at(t, i + 1, j - 2) || at(t, i + 2, j - 1) ||
                // -+
                at(t, i - 1, j + 2) || at(t, i - 2, j + 1) ||
                // ++
                at(t, i + 1, j + 2) || at(t, i + 2, j + 1);
      filled += ok;
      t[i][j] = ok;
    }
  }

  return filled;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int i0, j0, i1, j1;
  cin >> n >> m >> i0 >> j0 >> i1 >> j1;
  i0--;
  j0--;
  i1--;
  j1--;

  vector<vector<bool>> t(n, vector<bool>(m));
  for (auto &row : t)
    row.resize(m);

  t[i0][j0] = 1;
  while (1) {
    int filled = fill(t);
    if (!filled || t[i1][j1])
      break;
  }

  cout << (t[i1][j1] ? "YES\n" : "NO\n");

  return 0;
}
