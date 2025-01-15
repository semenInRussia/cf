// semenInRussia 2025
#include <bitset>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

const int N = 2e5;
vector<int> g[N];

int h[N];
bitset<N> used;

void dfs(int x, int fa = -1) {
  used[x] = true;
  h[x] = fa == -1 ? 0 : h[fa] + 1;
  for (int y : g[x]) {
    if (y == fa) {
      continue;
    }
    if (used[y] && h[y] < h[x]) {
      cout << (x + 1) << " " << (y + 1) << "\n";
    } else if (!used[y]) {
      // _g[y].push_back(x);
      cout << (y + 1) << " " << (x + 1) << "\n";
      dfs(y, x);
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  dfs(0, -1);
}
