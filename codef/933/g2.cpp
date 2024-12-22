// semenInRussia 2024
// http..
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;

const int N = 2e5 + 100;
int r[N];
bool used[N];
bool cycle[N];
int d[N];

vector<int> g[N];

void dfs(int x, int fa = -1) {
  d[x] = 1;
  for (int y : g[x]) {
    if (cycle[y] || y == fa) {
      continue;
    }
    dfs(y, x);
    d[x] += d[y];
  }
}

void solve() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> r[i];
    r[i]--;
    d[i] = 0;
    cycle[i] = used[i] = 0;
    g[i].clear();
  }

  for (int i = 0; i < n; i++) {
    if (used[i]) {
      continue;
    }

    vector<int> path;

    int j = i;
    while (!used[j]) {
      used[j] = 1;
      path.push_back(j);
      j = r[j];
    }

    auto it = find(path.begin(), path.end(), j);

    if (it == path.end()) {
      continue;
    }

    for (; it != path.end(); it++) {
      cycle[*it] = 1;
      d[*it] = 0;
    }
  }

  fill(used, used + n, 0);

  for (int i = 0; i < n; i++) {
    g[r[i]].push_back(i);
    g[i].push_back(r[i]);
  }

  int ans = 2;

  for (int i = 0; i < n; i++) {
    if (cycle[i]) {
      dfs(i);
      for (int y : g[i]) {
        if (!cycle[y]) {
          ans = max(ans, d[y] + 2);
        }
      }
    }
  }

  cout << ans << "\n";
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
