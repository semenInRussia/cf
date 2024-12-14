// semenInRussia 2024
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll INF = 1e17;

const int N = 3e5;
int c[N];
ll ans[N];
vector<pair<int, int>> g[N];

struct node {
  bool skip = 0;
  ll lazy = +INF;
  pair<ll, int> min;
};

node operator*(node a, node b) {
  node c;
  c.min = min(a.min, b.min);
  c.skip = a.skip && b.skip;
  return c;
}

node t[N * 2];
int n;

void build(int k, int x = 0, int l = 0, int r = n) {
  if (r - l == 1) {
    ll dx = k == l ? 0 : +INF;
    t[x].min = {dx, l};
    t[x].skip = 0;
    t[x].lazy = +INF;
    return;
  }
  int m = (r + l) / 2;
  build(k, 2 * x + 1, l, m);
  build(k, 2 * x + 2, m, r);
  t[x] = t[2 * x + 1] * t[2 * x + 2];
}

void apply(int x, ll v) { // min=
  if (!t[x].skip) {
    t[x].min.first = min(t[x].min.first, v);
    t[x].lazy = min(t[x].lazy, v);
  }
}

void push(int x, int len) {
  if (len > 1) {
    ll v = t[x].lazy;
    apply(2 * x + 1, v);
    apply(2 * x + 2, v);
    t[x].lazy = +INF;
  }
}

// mark as ignored in dot
void skip(int i, int x = 0, int l = 0, int r = n) {
  if (r - l == 1) {
    t[x].skip = 1;
    t[x].min = {+INF, l};
    return;
  }
  int m = (r + l) / 2;
  push(x, r - l);
  if (i < m) {
    skip(i, 2 * x + 1, l, m);
  } else {
    skip(i, 2 * x + 2, m, r);
  }
  t[x] = t[2 * x + 1] * t[2 * x + 2];
}

// on range (min=)
void update(int ql, int qr, ll v, int x = 0, int l = 0, int r = n) {
  if (l >= ql && r <= qr) {
    apply(x, v);
    return;
  }
  if (r <= ql || l >= qr || t[x].skip) {
    return;
  }
  push(x, r - l);
  int m = (r + l) / 2;
  update(ql, qr, v, 2 * x + 1, l, m);
  update(ql, qr, v, 2 * x + 2, m, r);
  t[x] = t[2 * x + 1] * t[2 * x + 2];
}

void solve() {
  int m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }

  for (int i = 0; i < m; i++) {
    int x, y, c;
    cin >> x >> y >> c;
    x--, y--;
    g[x].push_back({y, c});
    g[y].push_back({x, c});
  }

  build(0);

  for (int i = 0; i < n; i++) {
    ans[i] = +INF;
  }

  ans[0] = 0;

  // Dijkstra
  for (int z = 0; z < n; z++) {
    auto [dx, x] = t[0].min;
    if (dx == +INF) {
      break;
    }
    ans[x] = dx;

    update(0, x, dx + c[x]);
    if (x + 1 < n) {
      update(x + 1, n, dx + c[x]);
    }

    for (auto [y, w] : g[x]) {
      update(y, y + 1, dx + w);
    }
    skip(x);
  }

  for (int i = 0; i < n; i++) {
    if (ans[i] == +INF) {
      ans[i] = -1;
    }
    cout << ans[i] << ' ';
  }

  cout << '\n';
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
