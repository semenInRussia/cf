// semenInRussia 2024
// https://cses.fi/problemset/task/1680
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int N = 2e5, inf = 1e9 + 5;
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

  if (beg > en) {
    cout << "IMPOSSIBLE";
    return 0;
  }

  f[0] = 1;
  for (int i = beg; i < n; i++) {
    int x = o[i];
    f[x] = -inf;
    for (int y : t[x]) {
      if (f[y] + 1 > f[x]) {
        prv[x] = y;
        f[x] = f[y] + 1;
      }
    }
  }

  //
  vector<int> path;
  for (int x = n - 1; x != 0; x = prv[x]) {
    path.push_back(x);
  }
  path.push_back(0);
  reverse(path.begin(), path.end());

  // display
  cout << f[n - 1] << '\n';
  for (int d : path) {
    cout << (d + 1) << ' ';
  }
}
