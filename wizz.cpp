// Copyright 2024 semenInRussia

// CF [dfs] [graphs] *2300
// https://codeforces.com/contest/860/problem/D

#include <array>
#include <iostream>
#include <set>
#include <vector>

using namespace std;
using pii = pair<int, int>;

const int maxn = 2e5;
set<pii> ue;
vector<int> g[maxn];
vector<array<int, 3>> answ;
bool used[maxn];

bool dfs(int u, int p) {
  used[u] = true;
  int v1 = -1;
  for (int v : g[u]) {
    if (v == p || used[v])
      continue;

    bool ok = dfs(v, u); // {u, v} is OK?
    if (ok) {
      if (v1 == -1)
        v1 = v;
      else
        answ.push_back({v1, u, v}), v1 = -1;
    }
  }
  if (v1 == -1 || p == -1)
    return true;

  // use {u, p}
  answ.push_back({v1, u, p});
  return false;
}

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b), g[b].push_back(a);
  }

  for (int u = 0; u < n; u++)
    if (!used[u])
      dfs(u, -1);

  cout << answ.size() << '\n';
  for (auto e : answ) {
    for (int u : e)
      cout << (u + 1) << ' ';
    cout << '\n';
  }
}
