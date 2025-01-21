// semenInRussia 2025
#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
  int n, s;
  cin >> n >> s;

  vector<vector<int>> t(n);

  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    t[i].resize(k);
    for (int &x : t[i]) {
      cin >> x;
    }
  }

  vector<vector<pair<int, int>>> prv(n, vector<pair<int, int>>(s + 1));
  vector<pair<int, int>> last(s + 1);
  vector<int> g(s + 1), f(s + 1);
  g[0] = 1;

  for (int i = 0; i < n; i++) {
    int k = (int)t[i].size();

    // add every element of t[i]
    for (int j = 0; j < k; j++) {
      int c = t[i][j];
      for (int x = s; x >= c; x--) {
        if (f[x]) {
          continue;
        }
        f[x] = g[x - c] || f[x - c];
        if (f[x]) {
          last[x] = {i, j};
          prv[i][x] = last[x - c];
        }
      }
    }

    swap(f, g);
    fill(f.begin(), f.end(), 0);
  }

  if (!g[s]) {
    cout << "No";
    return 0;
  }

  vector<vector<int>> ans(n);

  int x = s;
  auto [i, j] = last[x];

  while (x != 0) {
    ans[i].push_back(j);
    auto v = prv[i][x];
    x -= t[i][j];
    assert(x >= 0);
    i = v.first;
    j = v.second;
  }

  cout << "Yes\n";
  for (auto &row : ans) {
    cout << row.size() << "\n";
    for (int j : row) {
      cout << (j + 1) << " ";
    }
    cout << "\n";
  }
}
