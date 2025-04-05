// semenInRussia 2025
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

#ifdef home
#include "C:/Users/hrams/cf/debug.h"
#else
#define debug(...) ;
#endif

using namespace std;

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<int> used(n * m);
    vector<vector<int>> a(n);
    for (auto &row : a) {
      row.resize(m);
      for (int &x : row) {
        cin >> x;
        x--;
      }
    }

    vector<int> cnt(n * m), neigh(n * m);

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int x = a[i][j];
        cnt[x]++;
        if ((i > 0 && a[i - 1][j] == x) || (j > 0 && a[i][j - 1] == x) ||
            (j + 1 < m && a[i][j + 1] == x) ||
            (i + 1 < n && a[i + 1][j] == x)) {
          neigh[x] = true;
        }
      }
    }

    int ans = 0;
    for (int x = 0; x < n * m; x++) {
      if (cnt[x]) {
        ans += 1 + neigh[x];
      }
    }

    bool mat = *max_element(neigh.begin(), neigh.end());

    cout << ans - 1 - mat << "\n";
  }
}
