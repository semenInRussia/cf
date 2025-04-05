// semenInRussia 2025
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5 + 100;
vector<int> g[N];

int col[N];

void dfs(int x, int c) {
  if (col[x]) {
    return;
  }
  col[x] = c;
  for (int y : g[x]) {
    dfs(y, 3 - c);
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  for (int i = 0; i < n; i++) {
    dfs(i, 1);
  }

  bool ok = true;

  for (int x = 0; x < n; x++) {
    if (g[x].empty()) {
      ok = false;
    }
  }

  if (!ok) {
    cout << "-1";
    return 0;
  }

  for (int i = 0; i < n; i++) {
    cout << col[i] << " ";
  }
}
