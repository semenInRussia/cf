// semenInRussia 2024
// https://contest.yandex.ru/contest/69757/problems/D/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;

  vector<vector<int>> a(n, vector<int>(m, 0));
  for (auto &row : a) {
    for (auto &el : row) {
      cin >> el;
    }
  }

  vector<vector<int>> row(n), col(m);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      row[i].push_back(a[i][j]);
      col[j].push_back(a[i][j]);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      sort(row[i].begin(), row[i].end());
      sort(col[j].begin(), col[j].end());
    }
  }

  int q;
  cin >> q;

  while (q--) {
    int i, j, k;
    cin >> i >> j >> k;

    auto count = [&a, i, j](vector<int> &v, int x) { // count >= x
      return upper_bound(v.begin(), v.end(), x) - v.begin();
    };

    // first count<() >= k

    int l = -1, r = +1e9 + 1;
    while (r - l > 1) {
      int m = (r - l) / 2 + l;

      // count <= m
      int cnt = count(row[i], m) + count(col[j], m);
      if (a[i][j] <= m) {
        cnt--;
      }

      if (cnt >= k) {
        r = m;
      } else {
        l = m;
      }
    }

    cout << r << "\n";
  }
}
