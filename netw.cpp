// Copyright 2024 semenInRussia

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int n, m;

const int maxn = 2e5 + 10;
int answ[maxn];
vector<set<int>> g;
set<int> s;

void dfs(int v, int num) {
  s.erase(v);
  answ[num]++;

  auto it = s.begin();
  while (it != s.end()) {
    int u = *it;
    if (s.count(u) && !g[u].count(v))
      dfs(u, num);
    it = s.upper_bound(u);
  }
}

int main() {
  cin >> n >> m;
  g.resize(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].insert(b);
    g[b].insert(a);
  }

  for (int i = 0; i < n; i++)
    s.insert(i);

  int cnt = 0;
  for (int i = 0; i < n; i++)
    if (s.count(i))
      dfs(i, cnt++);

  sort(answ, answ + cnt);

  cout << cnt << endl;
  for (int i = 0; i < cnt; i++)
    cout << answ[i] << ' ';
}
