// semenInRussia 2024
// find the Lowest Common Ancestor (LCA) in the tree of 2 given node in
// O(log n), with preprocessing O(n log n)
#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5, L = 21;
int up[N][L];
int h[N];
int tin[N], tout[N];

vector<int> g[N];

int ti = 0;

void dfs(int x, int fa = -1) {
  tin[x] = ti++;
  h[x] = fa == -1 ? 0 : h[fa] + 1;

  // build up[x]
  fill(up[x], up[x] + L, -1);
  up[x][0] = fa;
  for (int i = 0; i + 1 < L && up[x][i] != -1; i++) {
    up[x][i + 1] = up[up[x][i]][i];
  }

  for (auto y : g[x]) {
    if (y != fa) {
      dfs(y, x);
    }
  }

  tout[x] = ti++;
}

int p(int x, int y) { // return y in x
  return tin[x] <= tin[y] && tin[y] <= tout[x];
}

int lca(int x, int y) {
  if (p(x, y)) {
    return x;
  }
  if (p(y, x)) {
    return y;
  }
  for (int j = L - 1; j >= 0; j--) {
    if (up[x][j] == -1) {
      continue;
    }
    if (!p(up[x][j], y)) {
      x = up[x][j];
    }
  }
  return up[x][0];
}

int dist(int x, int y) {
  int z = lca(x, y);
  return h[x] - h[z] + h[y] - h[z];
}

// k'th ancestor of x or -1 if jump over root
int jump(int x, int k) {
  for (int j = L - 1; j >= 0 && x != -1; j--) {
    if ((k >> j) & 1) {
      x = up[x][j];
    }
  }

  return x;
}

int main() {
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int x;
    cin >> x;
    x--;
    g[x].push_back(i);
    g[i].push_back(x);
  }

  ti = 0;
  dfs(0);
}
