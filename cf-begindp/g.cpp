// semenInRussia 2024
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

const int N = 1e4 + 100;
vector<int> g[N], t[N], order;
int f[N];
bool used[N];

void dfs(int x) {
  used[x] = 1;
  for (int y : g[x])
    if (!used[y])
      dfs(y);
  order.push_back(x);
}

int main() {
  freopen("longpath.in", "r", stdin);
  freopen("longpath.out", "w", stdout);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
    t[b].push_back(a);
  }
  for (int x = 0; x < n; x++)
    if (!used[x])
      dfs(x);
  reverse(order.begin(), order.end());
  for (int x : order) {
    f[x] = 0;
    for (int y : t[x])
      f[x] = max(f[x], f[y] + 1);
  }
  cout << *max_element(f, f + n);
}
