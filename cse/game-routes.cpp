// semenInRussia 2024
// https://cses.fi/problemset/task/1681
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int N = 2e5, inf = 1e9 + 5;
const int mod = 1e9 + 7;
vector<int> g[N], t[N];

bool used[N];
int o[N];
int ti = 0;
void dfs(int x) {
  used[x] = 1;
  for (int y : g[x]) {
    if (!used[y]) {
      dfs(y);
    }
  }
  o[ti++] = x;
}

int f[N], prv[N];
int main() {
  int n, m;
  cin >> n >> m;
  for (int j = 0; j < m; j++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
    t[b].push_back(a);
  }

  // topological sort
  for (int i = 0; i < n; i++) {
    if (!used[i]) {
      dfs(i);
    }
  }
  reverse(o, o + n);

  // fill DP
  int beg = find(o, o + n, 0) - o + 1;
  int en = find(o, o + n, n - 1) - o;

  f[0] = 1;
  for (int i = beg; i < n; i++) {
    int x = o[i];
    for (int y : t[x]) {
      f[x] += f[y];
      if (f[x] >= mod) {
        f[x] -= mod;
      }
    }
  }

  cout << f[n - 1] << '\n';
}
