// semenInRussia 2024
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#pragma GCC target("avx2")

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);

  int n, m, A, B;
  cin >> n >> m >> A >> B;

  vector<vector<int>> a(n, vector<int>(0, m));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }

  vector<vector<int64_t>> b(n + 5, vector<int64_t>(0, m + 5));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      b[i + 1][j + 1] = b[i][j + 1] + b[i + 1][j] - b[i][j] + a[i][j];
    }
  }

  vector<int> s;

  s.reserve(n * m * n * m);

  for (int i1 = 0; i1 < n; i1++) {
    for (int j1 = 0; j1 < m; j1++) {
      for (int i2 = i1 + 1; i2 <= n; i2++) {
        for (int j2 = j1 + 1; j2 <= m; j2++) {
          int64_t v = b[i2][j2] - b[i1][j2] - b[i2][j1] + b[i1][j1];
          if (v <= 1ll * B) {
            s.push_back(v);
          }
        }
      }
    }
  }

  sort(s.begin(), s.end());
  int64_t ans = 0;

  for (int i = 0; i < int(s.size()); i++) {
    int x = s[i];

    if (i + 1 == int(s.size())) {
      continue;
    }

    // A <= y + x <= B
    // y <= B - x
    // y >= A - x

    auto l = lower_bound(s.begin() + i + 1, s.end(), A - x);
    auto r = lower_bound(s.begin() + i + 1, s.end(), B - x + 1);
    int p = r - l;
    ans += max(0, p);
  }

  // O(n * n * n * n * log it) ~= 5 * 1e7

  cout << ans;
}
