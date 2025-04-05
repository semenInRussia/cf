// semenInRussia 2024
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

const int N = 3e5 + 100;

vector<int> g[N];

ll a[N];

vector<pair<int, int>> v[N];

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  for (int x = 0; x < n; x++) {
    for (int y : g[x]) {
      v[x].push_back({a[y], y});
    }
    sort(v[x].rbegin(), v[x].rend());
    v[x].resize(min((int)v[x].size(), 4));
  }

  // path len=4

  pair<ll, vector<int>> ans = {0, {}};

  for (int x = 0; x < n; x++) {
    // len=1
    ans = max(ans, {a[x], {x}});

    for (int y : g[x]) {
      if (x == y) {
        continue;
      }

      // len=2
      ans = max(ans, {a[x] + a[y], {x, y}});

      for (auto [az, z] : v[x]) {
        if (z == x || z == y) {
          continue;
        }
        // path len=3
        ans = max(ans, {a[x] + a[y] + a[z], {y, x, z}});

        // len=4
        for (auto [aw, w] : v[y]) {
          if (w == z || w == z || w == x) {
            continue;
          }
          ans = max(ans, {a[x] + a[y] + az + aw, {z, x, y, w}});
        }
      }
    }
  }

  cout << ans.second.size() << "\n";
  for (int x : ans.second) {
    cout << (x + 1) << " ";
  }
}
