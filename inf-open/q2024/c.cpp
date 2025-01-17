// semenInRussia 2024
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,fma,bmi2,tune=native")

const int N = 2e5 + 100;
vector<int> g[N];

map<pair<int, int>, bool> e;

int64_t &setmax(int64_t &v, int64_t op) { return v = max(v, op); }

bool &can(pair<int, int> xy) {
  if (xy.first > xy.second) {
    swap(xy.first, xy.second);
  }
  return e[xy];
}

bool &can(int x, int y) { return can({x, y}); }

int par[N], h[N];

pair<int, int> ed[N];
int64_t _f[N][2];

int64_t &f(int x, bool p) { return _f[x][p]; }

void dfs(int x, int fa = -1) {
  par[x] = fa;
  h[x] = fa == -1 ? 0 : h[fa] + 1;

  f(x, 1) = 0;
  f(x, 0) = 0;

  // f(x, 1) + ... + f(x, 1)
  // - f(x, 1) + f(x, 0)

  int64_t ad = 0;

  for (int y : g[x]) {
    if (can(x, y) && fa != y) {
      dfs(y, x);
      f(x, 0) += max(f(y, 0), f(y, 1));
      ad = max(ad, -f(y, 1) + f(y, 0) + 1);
    }
  }

  f(x, 1) = f(x, 0) + ad;
}

void solve2(int n) {
  // cout << "solve2\n";

  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
  }

  set<int> s;
  s.insert(n);
  s.insert(0);

  int q;
  cin >> q;

  // cout << "q=" << q << "\n";

  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int e;
      cin >> e;
      int a = e;
      // int b = e + 1;
      auto it = s.find(a);
      if (it == s.end()) {
        s.insert(e);
      } else {
        s.erase(it);
      }
    } else {
      int x;
      cin >> x;
      int b = *s.lower_bound(x);
      int a = *prev(s.lower_bound(x));
      int ans = b - x + x - a - 1;
      ans = (ans + 1) / 2;
      cout << ans << "\n";
    }
  }
}

void change(int x) {
  for (; x != -1; x = par[x]) {
    f(x, 1) = 0;
    f(x, 0) = 0;

    int64_t ad = 0;

    for (int y : g[x]) {
      if (can(x, y) && par[x] != y) {
        f(x, 0) += max(f(y, 0), f(y, 1));
        ad = max(ad, -f(y, 1) + f(y, 0) + 1);
      }
    }

    f(x, 1) = f(x, 0) + ad;
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int tg, n;
  cin >> tg >> n;

  if (tg == 2) {
    solve2(n);
    return 0;
  }

  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    g[x].push_back(y);
    g[y].push_back(x);
    ed[i] = {x, y};
    can(x, y) = 1;
  }

  dfs(0, -1);

  int q;
  cin >> q;
  for (int j = 0; j < q; j++) {
    int t;
    cin >> t;
    if (t == 1) {
      int i;
      cin >> i;
      can(ed[i]) = !can(ed[i]);
      auto [x, y] = ed[i];
      if (h[x] > h[y]) {
        swap(x, y);
      }
      change(y);
    } else {
      int x;
      cin >> x;
      x--;
      while (par[x] != -1 && can(x, par[x])) {
        x = par[x];
      }
      cout << max(f(x, 0), f(x, 1)) << "\n";
    }
  }
}
