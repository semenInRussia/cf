// semenInRussia 2025
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>

using namespace std;

const int N = 55000;
vector<pair<int, int>> g[N];

int p[N];

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    g[x].push_back({y, i});
    g[y].push_back({x, i});
  }

  for (int i = 0; i < m; i++) {
    p[i] = i + 1;
  }

  mt19937 mt(1000);

  bool ok = true;

  for (int tt = 0; tt < m; tt++) {
    for (int x = 0; x < n; x++) {
      int r = -1;
      for (auto [y, j] : g[x]) {
        if (r == -1) {
          r = p[j];
        }
        r = gcd(p[j], r);
      }

      if (r != 1) {
        ok = false;
      }
    }

    if (ok) {
      for (int j = 0; j < m; j++) {
        cout << p[j] << "\n";
      }
      return 0;
    }

    shuffle(p, p + m, mt);
  }

  cout << "-1";
}
