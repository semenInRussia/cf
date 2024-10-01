// semenInRussia 2024
// https://codeforces.com/contest/1997/problem/D
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int N = 2e5;
const ll inf = 1e18 + 5;
int a[N], mn[N];
ll d[N];

vector<int> g[N];

void dfs(int x, int p = -1) {
  d[x] = a[x];
  if (g[x].empty()) {
    return;
  }

  ll op = +inf;
  // d[x] - is maximum possible minimum of subtree
  for (int y : g[x]) {
    dfs(y);
    op = min(op, d[y]);
  }
  if (a[x] >= op) {
    d[x] = op;
  } else { // value is lower than minimum, can increase
    ll v = op - a[x];
    d[x] = a[x] + (v / 2);
  }
}

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    g[i].clear();
  }
  for (int i = 1; i < n; ++i) {
    int p;
    cin >> p;
    g[p - 1].push_back(i);
  }
  dfs(0);
  ll m = +inf;
  for (int y : g[0]) {
    m = min(m, d[y]);
  }
  cout << (m + a[0]) << '\n';
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}
