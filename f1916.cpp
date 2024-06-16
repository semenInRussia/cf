// Copyright 2024 semenInRussia
// problem: 1916/f
// #graphs
//
// https://codeforces.com/problemset/problem/1916/F

using namespace std;

#include <algorithm>
#include <iostream>
#include <unordered_set>

using uset = unordered_set<int>;

const int maxn = 2000;

int n, n1, n2, m;
uset g[maxn];

bool seen[maxn];
int tin[maxn], fup[maxn];
int t = 0;
uset b;

void dfs(int v, int p = -1) {
  // tin[v] > fup[u]
  //
  // fup[v] = min(tin[v], tin[u] - back, fup[u] - tree)
  seen[v] = true;
  tin[v] = fup[v] = ++t;
  int children = 0;
  for (auto u : g[v]) {
    if (u == p)
      continue;
    if (seen[u]) {
      // back edge
      fup[v] = min(fup[v], tin[u]);
    } else {
      dfs(u, v);
      fup[v] = min(fup[v], fup[u]);
      if (tin[v] <= fup[u] && p != -1) {
        b.insert(u);
      }
      children++;
    }
  }
  if (p == -1 && children > 1) {
    b.insert(v);
  }
}

void solve() {
  cin >> n1 >> n2 >> m;
  n = n1 + n2;

  for (size_t i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    g[a].insert(b);
    g[b].insert(a);
  }

  dfs(1);
  // if we found unseen vertexes, then we have two components

  bool connected = true;
  for (auto t : seen) {
    if (!t) {
      connected = false;
      break;
    }
  }

  if (!connected) {
    // red is 1
    int nred = 0;
    // black is 0
    int nblack = 0;

    for (auto t : seen) {
      nred += t;
      nblack += !t;
    }

    int g1 = 1;
    int g2 = 0;
    if (n1 != nred) {
      swap(g1, g2);
    }

    // g1
    for (size_t i = 0; i < n; i++) {
      if (seen[i] == g1)
        cout << i << ' ';
    }
    cout << endl;

    // g2
    for (size_t i = 0; i < n; i++) {
      if (seen[i] == g2)
        cout << i << ' ';
    }
    cout << endl;
  }
}

int main() {
  size_t t;
  cin >> t;

  while (t--)
    solve();
}
