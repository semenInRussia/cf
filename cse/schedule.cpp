// semenInRussia 2024
// https://cses.fi/problemset/task/1679
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int N = 2e5;
vector<int> g[N];

int used[N];
bool cycle(int x) {
  used[x] = 1;
  for (int y : g[x]) {
    if (used[y] == 1) {
      return true;
    }
    if (used[y] == 0) {
      int a = cycle(y);
      if (a) {
        return a;
      }
    }
  }
  used[x] = 2;
  return false;
}

int ti = 0;
int o[N];
void dfs(int x) {
  used[x] = 1;
  for (int y : g[x]) {
    if (!used[y]) {
      dfs(y);
    }
  }
  o[ti++] = x;
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

  // find cycles?
  bool bad = false;
  for (int i = 0; i < n && !bad; i++) {
    if (!used[i]) {
      bad = cycle(i);
    }
  }

  if (bad) {
    cout << "IMPOSSIBLE";
    return 0;
  }

  // topoligical sort
  fill(used, used + n, 0);
  for (int i = 0; i < n; i++) {
    if (!used[i]) {
      dfs(i);
    }
  }
  reverse(o, o + n);
  for (int i = 0; i < n; i++) {
    cout << (o[i] + 1) << ' ';
  }
}
