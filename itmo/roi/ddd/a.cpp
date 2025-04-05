// semenInRussia 2025
#ifndef home
#pragma GCC optimize("O3,unroll-loops")
#endif
#define _USE_MATH_DEFINES
#include <algorithm>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdint>
#include <iostream>
#include <vector>
#ifndef home
#pragma GCC target("avx2")
#endif

using namespace std;

using T = long long;
using P = pair<T, T>;

#define X first
#define Y second

T dot(P a, P b) { return a.X * b.X + a.Y * b.Y; }
T cross(P a, P b) { return a.X * b.Y - a.Y * b.X; }

T dist(P a, P b) {
  auto l = a.X - b.X;
  auto r = a.Y - b.Y;
  return l * l + r * r;
}

T norm(P a) { return a.X * a.X + a.Y * a.Y; }

P operator-(P a, P b) { return {a.X - b.X, a.Y - b.Y}; }

double angle(P a, P b) { return abs(atan2(cross(a, b), dot(a, b))); }
bool rar(P a, P b) { return angle(a, b) < M_PI_4; }

const int N = 2e5 + 100;
P p[N];
vector<int> g[N];

int nxt[N], len[N];
int64_t dp[N];

int lef[N], rig[N];

void dfs(int a, int fa = -1) {
  // cerr << "dfs " << a << "\n";
  len[a] = dp[a] = 0;
  nxt[a] = -1;

  auto it = find(g[a].begin(), g[a].end(), fa);
  if (it != g[a].end()) {
    g[a].erase(it);
  }

  sort(g[a].begin(), g[a].end(), [&](auto i, auto j) {
    P s = p[i] - p[a];
    P t = p[j] - p[a];
    return cross(s, t) > 0;
  });

  int k = (int)g[a].size();

  if (k <= 2) {
    return;
  }

  for (int i = 0; i < k; i++) {
    for (int L = i - 1; L >= max(0, i - 5); L--) {
      for (int R = i + 1; R < min(k, i + 5); R++) {
        int l = g[a][L];
        int b = g[a][i];
        int r = g[a][R];

        P x = p[l] - p[a];
        P y = p[b] - p[a];
        P z = p[r] - p[a];
        bool ok = cross(x, y) > 0 && cross(z, y) < 0 && rar(y, x) &&
                  rar(y, z) && norm(y) >= norm(z) && norm(y) >= norm(x);

        if (ok) {
          dfs(b, a);
          auto op = dp[b] + dist(p[b], p[a]);
          if (op > dp[a]) {
            dp[a] = op;
            len[a] = len[b] + 1;
            nxt[a] = b;
            rig[a] = l;
            lef[a] = r;
          }
        }
      }
    }
  }
}

istream &operator>>(istream &in, P &v) {
  T x, y;
  in >> x >> y;
  v = {x, y};
  return in;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n, m, s;
  cin >> n >> m >> s;
  --s;

  // assert(n - 1 == m);

  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }

  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    --x;
    --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  dfs(s);

  cout << len[s] << " " << dp[s] << "\n";

  int a = s;
  for (int i = 0; i < len[s]; i++) {
    cout << lef[a] + 1 << " " << nxt[a] + 1 << " " << rig[a] + 1 << "\n";
    a = nxt[a];
  }
}
