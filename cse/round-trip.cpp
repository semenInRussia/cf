// semenInRussia 2024
// https://cses.fi/problemset/task/1669
#include <iostream>
#include <vector>
using namespace std;
const int N = 2e5;
bool used[N];
int h[N], fa[N];
vector<int> g[N];

int answ = -1; // x - is start city
int prelast = -1;

void dfs(int x, int p = -1) {
  h[x] = p == -1 ? 0 : h[p] + 1;
  fa[x] = p;
  used[x] = 1;
  for (int y : g[x]) {
    if (y == p) {
      continue;
    }
    if (used[y]) { // back
      if (h[x] - h[y] >= 2) {
        answ = x;
        prelast = y;
      }
    } else { // straight
      dfs(y, x);
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  for (int i = 0; i < n; i++) {
    if (!used[i]) {
      dfs(i);
    }
  }

  if (answ == -1) {
    cout << "IMPOSSIBLE";
    return 0;
  }

  int len = h[answ] - h[prelast] + 2;
  cout << len << '\n';

  int x = answ;
  cout << (x + 1) << ' ';
  while (x != prelast) {
    x = fa[x];
    cout << (x + 1) << ' ';
  }
  cout << (answ + 1);
}
