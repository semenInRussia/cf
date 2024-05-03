// Copyright 2024 semenInRussia

// https://codeforces.com/contest/1387/problem/A

#include <iostream>
#include <vector>

using namespace std;

const int inf = 1e9 + 7;
using pii = pair<int, int>;

int n, m;

vector<vector<pii>> g;

const int maxn = 1e5;
int answ[maxn], values[maxn], used[maxn];

int sum = 0;
bool dfs(int u, int val) { // only values
  values[u] = val;
  used[u] = true;
  sum += abs(val);
  for (auto p : g[u]) {
    int v = p.first;
    if (!used[v]) {
      if (!dfs(v, p.second - val))
        return false;
    } else if (values[v] + values[u] != p.second)
      return false;
  }
  return true;
}

bool solve(int v) {
  pii bst = {-1, -1}; // first=sum, second=x
  bool ok = false;
  for (int x = -200; x < +200; x++) {
    sum = 0;
    fill(used, used + n, 0);
    if (dfs(v, x))
      ok = true, bst = min(bst, {sum, x});
  }
  dfs(v, bst.second);
  return ok;
}

int main() {
  cin >> n >> m;
  g.resize(n);
  const int needs[3] = {0, 100, 200}; // needs[i] - expected sum of two
                                      // connected with edge colored i vertexes
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    g[a].push_back({b, needs[c]});
    g[b].push_back({a, needs[c]});
  }

  int num = 0;
  bool ok = true;
  for (int i = 0; i < n; i++)
    if (!values[i])
      if (!solve(i))
        ok = false;

  if (!ok)
    cout << "NO";
  else {
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
      if (values[i] < 0)
        printf("-");
      printf("%d.%02d ", values[i] / 100, abs(values[i] % 100));
    }
  }
}
