// semenInRussia 2025
#include <cassert>
#include <cstdint>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int N = 3e5 + 10;
vector<pair<int, int>> g[N];

bool used[N];

int main() {
  int n, m, p;
  cin >> n >> m >> p;

  for (int i = 0; i < m; i++) {
    int x, y, c;
    cin >> x >> y >> c;
    --x;
    --y;
    g[x].push_back({y, c});
  }

  int qq;
  cin >> qq;

  while (qq--) {
    int l, r, x;
    cin >> l >> r >> x;
    assert(x == 0);

    for (int i = 0; i < n; i++) {
      used[i] = false;
    }

    queue<int> q;
    q.push(0);
    used[0] = true;

    int cnt = 0;

    while (!q.empty()) {
      int x = q.front();
      q.pop();
      ++cnt;
      for (auto [y, c] : g[x]) {
        if (l <= c && c <= r && !used[y]) {
          q.push(y);
          used[y] = true;
        }
      }
    }

    cout << (cnt == n ? "Yes\n" : "No\n");
  }
}
