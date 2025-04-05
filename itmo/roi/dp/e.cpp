// semenInRussia 2025
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

const int N = 19;
vector<int> g[N];

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
#ifndef home
  freopen("mafia.in", "r", stdin);
  freopen("mafia.out", "w", stdout);
#endif
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    --x;
    --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  pair<int, int> ans = {n, 0};
  int bst = 0;

  for (int b = 0; b < (1 << n); b++) {
    bool ok = true;
    for (int x = 0; x < n && ok; x++) {
      for (int y : g[x]) {
        if (((~b >> x) & 1) && ((~b >> y) & 1)) {
          ok = false;
          break;
        }
      }
    }
    if (ok) {
      int k = __builtin_popcount(b);
      if (k < ans.first) {
        bst = b;
        ans = {k, 1};
      } else if (k == ans.first) {
        ans.second++;
      }
    }
  }

  cout << ans.first << " " << ans.second << "\n";
  for (int x = 0; x < n; x++) {
    if ((bst >> x) & 1) {
      cout << (x + 1) << " ";
    }
  }
}
