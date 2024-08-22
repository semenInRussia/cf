// semenInRussia 2024
// https://cses.fi/problemset/task/1160
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int N = 2e5, inf = 1e9 + 5;
vector<int> g[N];
// cycle[x] - size of cycle which have x
int t[N], cycle[N], id_in_cycle[N], tree_id[N];
int cycle_sz[N], h[N];
bool used[N], in_cycle[N];
int tin[N], tout[N];

int tim = 0;
void dfs(int x, int p = -1) {
  used[x] = 1;
  h[x] = 0;
  tree_id[x] = x;
  tin[x] = tim++;
  if (p != -1) {
    h[x] = h[p] + 1;
    tree_id[x] = tree_id[p];
    id_in_cycle[x] = id_in_cycle[p];
    cycle_sz[x] = cycle_sz[p];
    cycle[x] = cycle[p];
  }
  for (int y : g[x]) {
    if (!used[y]) {
      dfs(y, x);
    }
  }
  tout[x] = tim;
}

// cycle_sz[]
// in_cycle[]
// id_in_cycle[]
// cycle[]
// tree_id
// tin, tout

int main() {
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> t[i];
    t[i]--;
    cycle[i] = -1;
    id_in_cycle[i] = -1;
    g[t[i]].push_back(i);
  }

  // fill cycle[x]
  // cycle[x] - id of cycle
  for (int i = 0; i < n; i++) {
    if (used[i]) {
      continue;
    }
    vector<int> path;
    int x;
    for (x = i; !used[x]; x = t[x]) {
      used[x] = 1;
      path.push_back(x);
    }

    int beg = find(path.begin(), path.end(), x) - path.begin();
    for (int i = beg; i < (int)path.size(); i++) {
      int y = path[i];
      cycle[y] = path[beg];
      id_in_cycle[y] = i - beg;
      in_cycle[y] = 1;
      cycle_sz[y] = int(path.size()) - beg;
    }
  }

  copy(in_cycle, in_cycle + n, used);
  for (int i = 0; i < n; i++) {
    if (in_cycle[i]) {
      tim = 0;
      dfs(i);
    }
  }

  // answer on queries
  for (int j = 0; j < q; j++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    int ans = -1;
    if (cycle[a] == cycle[b] && in_cycle[b]) {
      int sz = cycle_sz[a];
      ans = h[a] + (id_in_cycle[b] - id_in_cycle[a] + sz) % sz;
    } else if (cycle[a] == cycle[b] && tree_id[a] == tree_id[b] &&
               tin[a] >= tin[b] && tin[a] < tout[b]) {
      ans = h[a] - h[b];
    }
    cout << ans << '\n';
  }
}
