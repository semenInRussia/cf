// Copyright 2024 semenInRussia

#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;
using uset = unordered_set<size_t>;

enum Direction {
  Forward,
  Back,
};

Direction query(vector<uset> &g, size_t u, size_t v) {
  if (g[u].count(v)) {
    return Forward;
  } else if (g[v].count(u)) {
    return Back;
  }

  cout << "? " << u << ' ' << v << endl;
  string ans;
  cin >> ans;
  if (ans == "forward") {
    g[u].insert(v);
    return Forward;
  } else {
    g[v].insert(u);
    return Back;
  }
}

void dfs(int v, vector<size_t> &ans, vector<bool> &used, vector<uset> &g) {
  used[v] = true;
    
  for (size_t u = 1; u < g.size(); u++) {
    if (used[u])
      continue;
    if (query(g, v, u) == Forward) {
      dfs(u, ans, used, g);
    }
  }
  ans.push_back(v);
}

void test_case(size_t _tg) {
  size_t n;
  cin >> n;

  vector<bool> used(n + 1, false);
  vector<uset> g(n + 1);
  vector<size_t> ans;

  for (int i = 1; i <= n; i++)
    if (!used[i])
      dfs(i, ans, used, g);

  int x = ans.front();

  // check g[x]
  for (size_t u = 1; u <= n && g[u].size() < 2; u++) {
    if (u == x)
      continue;
    query(g, u, x);
  }
  if (g[x].size() > 1) {
    cout << "! -1" << endl;
  } else {
    cout << "! " << x << endl;
  }

  string _verdict;
  cin >> _verdict;
}

int main() {
  int tg, t;
  cin >> tg >> t;

  while (t--) {
    test_case(tg);
  }

  return 0;
}
