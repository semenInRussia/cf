// semenInRussia 2024
// https://cses.fi/problemset/task/1678
#include <algorithm>
#include <cassert>
#include <csignal>
#include <iostream>
#include <vector>
using namespace std;

const int N = 2e5;
int used[N], h[N], fa[N];
vector<int> g[N];

int last = -1, pre = -1;
// last->x1->x2->...->prelast->last

void dfs(int x, int p = -1) {
  used[x] = 1;
  h[x] = p == -1 ? 0 : h[p] + 1;
  fa[x] = p;
  for (int y : g[x]) {
    if (used[y] == 1 && h[y] < h[x]) { // found
      last = x;
      pre = y;
    } else if (used[y] == 0) {
      dfs(y, x);
    }
  }
  used[x] = 2;
}

int main() {
  int n, m;
  cin >> n >> m;
  for (int j = 0; j < m; j++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
  }

  for (int i = 0; i < n; i++) {
    if (!used[i]) {
      dfs(i);
    }
  }

  // cout << last << ' ' << pre << '\n';

  vector<int> path = {};
  for (int x = last; x != pre; x = fa[x]) {
    path.push_back(x);
  }
  path.push_back(pre);
  path.push_back(last);
  reverse(path.begin(), path.end());

  if (last == -1) {
    cout << "IMPOSSIBLE";
    return 0;
  }

  //--
  cout << path.size() << '\n';
  for (int x : path) {
    cout << (x + 1) << ' ';
  }
}
