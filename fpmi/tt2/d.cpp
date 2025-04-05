// semenInRussia 2025
#pragma GCC optimize("Ofast,unroll-loops")
#include <cstdint>
#include <iostream>
#include <vector>
#pragma GCC target("avx2")

using namespace std;

void bad() {
  cout << "No\n";
  exit(0);
}

const int N = 505;
vector<int> g[N];
bool used[N];
int col[N];

int len = 0;

void dfs(int x, int v) {
  used[x] = 1;
  col[x] = v;
  len++;
  for (int y : g[x]) {
    if (!used[y]) {
      dfs(y, v);
    }
  }
}

int sz[N];
bool red[N];

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  int k = 0;

  for (int i = 0; i < n; i++) {
    if (!used[i]) {
      dfs(i, k);
      sz[k++] = len;
      len = 0;
    }
  }

  if (k == 2) {
    // check that two clicks
    bool ok = true;
    for (int i = 0; i < n; i++) {
      int s = sz[col[i]];
      if ((int)g[i].size() != s - 1) {
        ok = false;
      }
    }

    if (!ok) {
      bad();
    }

    cout << "Yes\n";
    for (int i = 0; i < n; i++) {
      cout << "ac"[col[i]];
    }

    return 0;
  }

  int r = 0;

  for (int i = 0; i < n; i++) {
    if ((int)g[i].size() == n - 1) {
      red[i] = true;
      r++;
    }
    used[i] = red[i];
  }

  if (r == 0) {
    bad();
  }

  k = 0;
  for (int i = 0; i < n; i++) {
    if (!used[i] && !red[i]) {
      dfs(i, k);
      sz[k++] = len;
      len = 0;
    }
  }

  if (k > 2) {
    bad();
  }

  bool ok = true;

  for (int i = 0; i < n; i++) {
    if (!red[i] && sz[col[i]] - 1 + r != (int)g[i].size()) {
      ok = false;
    }
  }

  if (!ok) {
    bad();
  }

  cout << "Yes\n";
  for (int i = 0; i < n; i++) {
    if (red[i]) {
      cout << "b";
    } else {
      cout << "ac"[col[i]];
    }
  }
}
