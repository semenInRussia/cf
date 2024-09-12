// semenInRussia 2024
// https://cses.fi/problemset/task/1686
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
#define all(a) a.begin(), a.end()

const int N = 2e5;
vector<int> g[N], _g[N], t[N];
int comp[N];
ll a[N], _a[N];

int o[N];
bool used[N];
int tim = 0;
ll f[N];
void dfs1(int x) {
  used[x] = 1;
  for (int y : g[x]) {
    if (!used[y]) {
      dfs1(y);
    }
  }
  o[tim++] = x;
}

void dfs2(int x, int num) {
  comp[x] = num + 1;
  for (int y : t[x]) {
    if (!comp[y]) {
      dfs2(y, num);
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
    t[b].push_back(a);
  }

  // top sort
  for (int i = 0; i < n; i++) {
    if (!used[i]) {
      dfs1(i);
    }
  }
  reverse(o, o + n);

  // components
  int num = 0;
  for (int i = 0; i < n; i++) {
    int x = o[i];
    if (!comp[x]) {
      dfs2(x, num++);
    }
  }

  for (int i = 0; i < n; i++) {
    comp[i]--;
  }

  // x => comp[x]
  for (int i = 0; i < n; i++) {
    _a[comp[i]] += a[i];
  }
  swap(_a, a);
  for (int x = 0; x < n; x++) {
    for (int y : g[x]) {
      if (comp[x] != comp[y]) {
        _g[comp[x]].push_back(comp[y]);
      }
    }
  }

  // build _t[] inverted _g[]
  for (int x = 0; x < num; x++) {
    sort(all(_g[x]));
    int u = unique(all(_g[x])) - _g[x].begin();
    _g[x].resize(u);
  }
  swap(_g, g);
  for (int i = 0; i < n; i++) {
    t[i].clear();
  }
  n = num;
  for (int x = 0; x < n; x++) {
    for (int y : g[x]) {
      t[y].push_back(x);
    }
  }

  // top sort
  fill(used, used + n + 1, 0);
  tim = 0;
  for (int i = 0; i < n; i++) {
    if (!used[i]) {
      dfs1(i);
    }
  }
  reverse(o, o + n);

  for (int i = 0; i < n; i++) {
    int x = o[i];
    f[x] = a[x];
    for (int y : t[x]) {
      f[x] = max(f[x], f[y] + a[x]);
    }
  }

  cout << *max_element(f, f + n);
}
