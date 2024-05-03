// Copyright 2024 semenInRussia

#include <iostream>
#include <vector>

using namespace std;

const int maxn = 2e5;
int d[maxn], answ = 0;
vector<int> g[maxn];

void dfs(int v, int p = -1) {
  int mx1 = 0, mx2 = 0;
  for (int u : g[v]) {
    if (p != u) {
      dfs(u, v);
      if (d[u] >= mx1)
        mx2 = mx1, mx1 = d[u];
      else if (d[u] >= mx2)
        mx2 = d[u];
    }
  }

  answ = max(answ, mx1 + mx2);
  d[v] = mx1 + 1;
}

int main() {
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b), g[b].push_back(a);
  }

  dfs(0);
  cout << answ << '\n';
}
