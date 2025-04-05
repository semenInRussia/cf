// semenInRussia
#include <iostream>
#include <queue>
#include <set>
#include <utility>
#include <vector>

using namespace std;

struct dsu {
  vector<int> p, w, sz;

  dsu(int n) {
    p.resize(n);
    w.resize(n);
    sz.resize(n);
    for (int i = 0; i < n; i++) {
      p[i] = i;
      w[i] = 0;
      sz[i] = 0;
    }
  }

  pair<int, int> get(int i) {
    if (p[i] == i) {
      return {i, 0};
    }
    auto g = get(p[i]);
    p[i] = g.first;
    w[i] += g.second;
    return {p[i], w[i]};
  }

  int join(int a, int b) {
    b = get(b).first;
    a = get(a).first;
    if (sz[a] > sz[b]) {
      swap(a, b);
    }
    p[a] = b;
    w[a] -= w[b];
    sz[b] += sz[a];
    return b;
  }

  void inc(int i, int v) {
    i = get(i).first;
    w[i] += v;
  }

  // get color
  int value(int i) {
    auto g = get(i);
    return (w[g.first] + g.second) & 1;
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> a(m);
  for (int i = 0; i < m; ++i) {
    cin >> a[i].first >> a[i].second;
    a[i].first--;
    a[i].second--;
  }

  int cnt = 1;

  set<int> v;

  dsu p(n);

  for (auto [x, y] : a) {
    bool ok = true;

    if (p.get(x).first == p.get(y).first) {
      if (p.value(x) == p.value(y)) {
        ok = false;
      }
    }

    if (!ok) {
      cnt++;
      for (int x : v) {
        p.p[x] = x;
        p.sz[x] = 1;
        p.w[x] = 0;
      }
      v.clear();
    }

    v.insert(x);
    v.insert(y);

    if (p.get(x).first != p.get(y).first) {
      if (p.value(x) == p.value(y)) {
        p.inc(x, +1);
      }
      p.join(x, y);
    }
  }

  cout << cnt;
}
