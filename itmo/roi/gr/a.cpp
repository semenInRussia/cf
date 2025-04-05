// semenInRussia 2025
#include <cassert>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5 + 5;
const int64_t infll = 1e18 + 5;
vector<int> g[N];
int s[N];

int n, m, c;

// { idx, size of }
vector<pair<int, int>> ops;

int used[N];
int d[N], h[N];
int r[N];
int cur = 0;

// find bridge;
// s[x] - size of subtree
void dfs(int x, int fa = -1) {
  // cerr << "cur: " << cur << "\n";
  used[x] = 1;
  d[x] = h[x] = fa == -1 ? 0 : h[fa] + 1;
  s[x] = 1;
  for (int y : g[x]) {
    if (y == fa) {
      continue;
    }
    if (!used[y]) {
      dfs(y, x);
      s[x] += s[y];
      d[x] = min(d[x], d[y]);
      if (d[y] > h[x]) {
        int a = s[y];
        ops.push_back({cur, a});
      }
    } else {
      d[x] = min(d[x], h[y]);
    }
  }
}

void solve() {
  cin >> n >> m >> c;
  for (int i = 0; i < n; i++) {
    g[i].clear();
    used[i] = false;
  }
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  ops.clear();

  vector<int> r;

  for (int i = 0; i < n; i++) {
    if (!used[i]) {
      cur = i;
      r.push_back(cur);
      dfs(i, -1);
    }
  }

  // cerr << "ops\n";
  // for (auto [x, sz] : ops) {
  //   cerr << x << " " << sz << "\n";
  // }
  // cerr << "---\n---\n";

  int f = (int)ops.size();
  for (int i = 0; i < f; i++) {
    auto [x, sz] = ops[i];
    ops.push_back({x, s[x] - sz});
  }

  long long ans = infll;

  int64_t ad = (((long long)r.size()) - 1) * c;
  // ad = 0;
  // cerr << "ad: " << ad << "\n";

  int k = (int)r.size();

  for (int b = 0; b < (1 << k); b++) {
    int A = 0;
    int B = 0;
    for (int i = 0; i < k; i++) {
      if ((b >> i) & 1) {
        A += s[r[i]];
      } else {
        B += s[r[i]];
      }
    }
    if (min(A, B) > 0) {
      ans = min(ans, 1ll * A * A + 1ll * B * B + ad);
    }
  }

  //  cerr << "ops: ";

  for (auto [x, a] : ops) {
    // cerr << x << " " << a << "\n";
    for (int b = 0; b < (1 << k); b++) {
      int A = a;
      int B = s[x] - a;

      for (int i = 0; i < (int)r.size(); i++) {
        if (r[i] == x) {
          continue;
        }
        if ((b >> i) & 1) {
          A += s[r[i]];
        } else {
          B += s[r[i]];
        }
      }
      // cerr << "AB: " << A << " " << B << "\n";
      if (min(A, B) > 0) {
        ans = min(ans, 1ll * A * A + 1ll * B * B + ad);
      }
    }
  }

  cout << (ans == +infll ? -1 : ans) << "\n";
  // cerr << "---\n";
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
