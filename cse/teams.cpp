// semenInRussia 2024
// https://cses.fi/problemset/task/1668
#include <iostream>
#include <vector>
using namespace std;
const int N = 2e5;
int color[N];
vector<int> g[N];

bool dfs(int x, int c) {
  color[x] = c;
  bool ok = 1;
  for (int y : g[x]) {
    if (!color[y]) {
      ok = dfs(y, 3 - c);
    } else {
      ok = color[y] != c;
    }
    if (!ok) {
      break;
    }
  }
  return ok;
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
  bool ok = 1;
  for (int i = 0; i < n && ok; i++) {
    if (!color[i]) {
      ok = dfs(i, 1);
    }
  }
  if (ok) {
    for (int i = 0; i < n; i++) {
      cout << color[i] << ' ';
    }
  } else {
    cout << "IMPOSSIBLE";
  }
}
