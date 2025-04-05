// semenInRussia 2025
#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5 + 5;
int f[N], t[N], _f[N];

vector<int> g[N];

int ti = 0;
int tin[N], tout[N];
int et[2 * N];
const int L = 20;
int up[N][L];

void dfs(int x, int fa = -1) {
  tin[x] = ti;
  et[ti++] = x;
  fill(up[x], up[x] + L, -1);
  up[x][0] = fa;
  for (int l = 0; l + 1 < L && up[x][l] != -1; l++) {
    up[x][l + 1] = up[up[x][l]][l];
  }
  for (int y : g[x]) {
    if (y != fa) {
      dfs(y, x);
    }
  }
  tout[x] = ti;
  et[ti++] = x;
}

bool par(int x, int y) { // x - parent
  return tin[x] <= tin[y] && tout[y] <= tout[x];
}

int lca(int x, int y) {
  if (par(x, y)) {
    return x;
  }
  if (par(y, x)) {
    return y;
  }

  for (int l = L - 1; l >= 0; l--) {
    int v = up[x][l];
    if (v != -1 && !par(v, y)) {
      x = v;
    }
  }

  return up[x][0];
}

struct query {
  int l;
  int r;
  int idx;
  int x = -1;
};

bool operator<(query a, query b) {
  return a.r < b.r || (a.r == b.r && a.idx < b.idx);
}

const int K = 512;
// const int K = 2;
vector<query> qu[N];

int n;
int k = 0; // queries

bool qry(int l, int r, int lc = -1) {
  if (r <= l) {
    return false;
  }
  qu[l / K].push_back({l, r, k++, lc});
  return true;
}

int64_t ans = 0;

bool used[N];
int cnt[2][N];

void add(int x) {
  used[x] ^= 1;
  ans -= 1ll * cnt[0][f[x]] * cnt[1][f[x]];
  if (used[x]) {
    cnt[t[x]][f[x]]++;
  } else {
    cnt[t[x]][f[x]]--;
  }
  ans += 1ll * cnt[0][f[x]] * cnt[1][f[x]];
  // cerr << "add " << x << " ans: " << ans << "\n";
}

void rem(int x) { add(x); }

const int Q = 1e5 + 10;
int64_t answ[Q];

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> f[i];
    _f[i] = f[i];
  }

  sort(_f, _f + n);
  int u = unique(_f, _f + n) - _f;
  for (int i = 0; i < n; i++) {
    f[i] = lower_bound(_f, _f + u, f[i]) - _f;
  }

  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  dfs(0);

  // cerr << "et: ";
  // for (int i = 0; i < ti; i++) {
  //   cerr << et[i] << " ";
  // }
  // cerr << "\n";

  int q;
  cin >> q;

  // [tout[x], tin[y]]
  // [tout[y], tin[x]]
  // x - parent: tin[x]; tin[y]
  // y - parent: tin[y]; tin[x]

  for (int o = 0; o < q; o++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    // cerr << x << ", " << y << ": ";
    if (par(x, y)) {
      // cerr << "par!\n";
      assert(qry(tin[x], tin[y] + 1));
    } else if (par(y, x)) {
      // cerr << "par!\n";
      assert(qry(tin[y], tin[x] + 1));
    } else {
      if (tout[x] > tin[y]) {
        swap(x, y);
      }
      // cerr << "with lca!\n";
      assert(tout[x] < tin[y] + 1);
      qry(tout[x], tin[y] + 1, lca(x, y));
      // assert(qry(tin[y], tin[x] + 1));
      // qu[tout[x] / K].back().x = lca(x, y);
    }
    // assert(int(qu[0].size()) == o + 1);
  }

  for (int j = 0; j * K <= ti; j++) {
    int L = j * K;
    int R = L + 1;
    add(et[L]);
    sort(qu[j].begin(), qu[j].end());
    for (auto q : qu[j]) {
      int l = q.l;
      int r = q.r;
      // cerr << "lr: " << l << ", " << r << ", idx : " << q.idx << "\n";
      // cerr << et[l] << " " << et[r - 1] << "\n";
      if (q.x != -1) {
        // cerr << "add lca " << q.x << "\n";
        add(q.x);
      }
      while (R < r) {
        add(et[R++]);
      }
      while (L < l) {
        rem(et[L++]);
      }
      while (L > l) {
        add(et[--L]);
      }
      // cerr << "used: ";
      // for (int i = 0; i < n; i++) {
      //   if (used[i]) {
      //     cerr << i << " ";
      //   }
      // }
      // cerr << "--\n";
      answ[q.idx] = ans;
      if (q.x != -1) {
        // cerr << "add lca " << q.x << "\n";
        add(q.x);
      }
    }

    // cerr << "clear\n";
    for (int i = L; i < R; i++) {
      rem(et[i]);
    }
    assert(ans == 0);
  }

  for (int j = 0; j < q; j++) {
    cout << answ[j] << "\n";
  }
}
