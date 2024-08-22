// semenInRussia 2024
// https://cses.fi/problemset/task/1678
#include <algorithm>
#include <cassert>
#include <csignal>
#include <iostream>
#include <vector>
using namespace std;

const int N = 2e5;
bool used[N];
vector<int> g[N], cyc, uxs;

int dfs(int x) {
  if (used[x]) { // I found new cycle
    assert(cyc.empty());
    cyc.push_back(x);
    return x;
  }

  used[x] = 1;
  for (int y : g[x]) {
    int a = dfs(y);
    if (a != -1) {
      cyc.push_back(x);
      if (a == x) {
        return -1;
      }
      return a;
    }

    if (!cyc.empty()) {
      return -1;
    }
  }
  return -1;
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

  for (int i = 0; i < n && cyc.empty(); i++) {
    if (!used[i]) {
      dfs(i);
    }
  }

  // if (!cyc.empty() && cyc.front() != cyc.back()) {
  //   cyc.clear();
  // }

  if (cyc.empty()) {
    cout << "IMPOSSIBLE";
    return 0;
  }

  reverse(cyc.begin(), cyc.end());
  cout << cyc.size() << '\n';
  for (int x : cyc) {
    cout << (x + 1) << ' ';
  }
}
