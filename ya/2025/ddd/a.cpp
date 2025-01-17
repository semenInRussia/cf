// semenInRussia 2024
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

#pragma GCC optimize("Ofast")

const int N = 4005;
int h[N];

vector<int> g[N];

struct fenw {
  int sz, n;
  vector<int> t;

  fenw(int _n) {
    n = _n;
    sz = 0;
    t.resize(n + 1);
  }

  int med() { return lower_bound(1 + sz / 2); }

  void add(int i, int v) {
    sz += v;
    i++;
    for (; i < (int)t.size(); i += i & -i) {
      t[i] += v;
    }
  }

  int lower_bound(int s) {
    int k = 0;
    for (int l = __lg(n); l >= 0; l--) {
      if (k + (1 << l) <= n && t[k + (1 << l)] < s) {
        k += (1 << l);
        s -= t[k];
      }
    }
    return k;
  }
};

int p[N];

void dfs0(int x, int fa = -1) {
  p[x] = fa;
  for (int y : g[x]) {
    if (y != fa) {
      dfs0(y, x);
    }
  }
}

int cnt[N];

void dfs1(fenw &s, int x, int fa) {
  s.add(x, +1);

  if (s.sz > 1 && (s.sz & 1)) {
    cnt[s.med()]++;
  }

  for (int y : g[x]) {
    if (y != fa) {
      dfs1(s, y, x);
    }
  }

  s.add(x, -1);
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  dfs0(0, -1);

  fenw s(n);

  for (int i = 0; i < n; i++) {
    dfs1(s, i, -1);
  }

  for (int i = 0; i < n; i++) {
    cout << cnt[i] << "\n";
  }
}
