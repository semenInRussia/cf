// semenInRussia 2024
#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

const int inf = 1e9 + 5;

const int N = 1e5 + 1000;
ll f[N][2][2];
int a[N];

vector<int> g[N];

void dfs(int x, int fa = -1) {
  if (g[x].size() == 1ull && x != 0) {
    f[x][a[x]][0] = 0;
    f[x][!a[x]][1] = 1;
    return;
  }

  for (int y : g[x]) {
    if (y == fa) {
      continue;
    }
    dfs(y, x);
  }

  // first; all children are black
  ll value = 0;
  ll df = +inf; // minimum cost of chnage
  bool o = 0;

  for (int y : g[x]) {
    if (y == fa) {
      continue;
    }
    auto v1 = f[y][1][1];
    auto v0 = f[y][1][0];

    if (min(v1, v0) == +inf) {
      value = +inf;
      break;
    }

    if (v1 < v0) {
      o ^= 1;
      value += v1;
      if (v0 != +inf) {
        df = min(df, v0 - v1);
      }
    } else {
      value += v0;
      if (v1 != +inf) {
        df = min(df, v1 - v0);
      }
    }
  }

  f[x][a[x] ^ o][0] = value;
  if (df != +inf) {
    f[x][a[x] ^ o ^ 1][0] = value + df;
  }

  // all children are white
  value = 0;
  df = +inf; // minimum cost of chnage
  o = 0;

  for (int y : g[x]) {
    if (y == fa) {
      continue;
    }

    auto v1 = f[y][0][1];
    auto v0 = f[y][0][0];

    if (min(v1, v0) == +inf) {
      value = +inf;
      break;
    }

    if (v1 < v0) {
      o ^= 1;
      value += v1;
      if (v0 != +inf) {
        df = min(df, v0 - v1);
      }
    } else {
      value += v0;
      if (v1 != +inf) {
        df = min(df, v1 - v0);
      }
    }
  }

  f[x][a[x] ^ o ^ 1][1] = value + 1;
  if (df != +inf) {
    f[x][a[x] ^ o][1] = value + df + 1;
  }

  // f[x][a[x] ^ o][0] = value;
  // if (df != +inf) {
  //   f[x][a[x] ^ o][0] = value + df;
  // }
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        f[i][j][k] = +inf;
      }
    }
  }

  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i] ^= 1;
  }

  dfs(0);

  ll ans = +inf;
  for (int i = 0; i < 2; i++) {
    ans = min(ans, f[0][1][i]);
  }

  if (ans == +inf) {
    cout << "impossible";
  } else {
    cout << ans;
  }
}
