// Copyright 2024 semenInRussia
// https://cses.fi/problemset/task/1666
#include <iostream>
#include <vector>
using namespace std;

const int N = 2e5;
int comp[N], city[N];
vector<int> g[N];

void dfs(int x, int num) {
  comp[x] = num;
  for (int y : g[x])
    if (!comp[y])
      dfs(y, num);
}

int main() {
  int n, m;
  cin >> n >> m;
  for (int j = 0; j < m; j++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  int num = 0;
  for (int x = 0; x < n; x++) {
    if (!comp[x]) {
      city[num] = x;
      num++;
      dfs(x, num);
    }
  }

  cout << num - 1 << '\n';
  for (int i = 1; i < num; i++) {
    cout << (city[i - 1] + 1) << ' ' << (city[i] + 1) << '\n';
  }
}
