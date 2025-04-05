// semenInRussia 2025
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

const int N = 1 << 18;
vector<int> g[N];
int p[N], a[N];
int nxt[N];
vector<int> t[N * 2];
int n;
int a2[N * 2];

int ti = 0;
int h[N];
int tin[N * 2], tout[N * 2];

void dfs(int x, int fa = -1) {
  a2[ti] = x;
  tin[x] = ti++;
  h[x] = fa == -1 ? 0 : h[fa] + 1;
  for (int y : g[x]) {
    if (y != fa) {
      dfs(y, x);
    }
  }
  a2[ti] = x;
  tout[x] = ti++;
}

struct fenw1 {
  vector<pair<int, int>> buf;
  vector<int> b;
  vector<vector<int>> t;

  int sz;

  void clear() {
    buf.clear();
    b.clear();
    t.clear();
  }

  void push(int a, int b) { buf.push_back({a, b}); }

  int id(int x) { return lower_bound(b.begin(), b.end(), x) - b.begin(); }

  void add(int r, int x) {
    r++;
    for (; r <= sz; r += r & -r) {
      t[r].push_back(x);
    }
  }

  int cnt(int r, int x) {
    int ans = 0;
    for (; r > 0; r -= r & -r) {
      auto it = lower_bound(t[r].begin(), t[r].end(), x);
      ans += t[r].end() - it;
    }
    return ans;
  }

  int qry(int l, int r) {
    l = id(l);
    r = id(r);
    return cnt(r, r) - cnt(l, r);
  }

  void build() {
    int n = (int)buf.size();
    b.resize(n * 2);
    for (int i = 0; i < n; i++) {
      b[i] = buf[i].first;
      b[n + i] = buf[i].second;
    }
    sort(b.begin(), b.end());
    int u = unique(b.begin(), b.end()) - b.begin();
    sz = u;
    b.resize(u);
    for (auto &[x, y] : buf) {
      x = id(x);
    }
    sort(buf.begin(), buf.end());
    t.resize(sz + 1);
    for (auto [x, y] : buf) {
      add(x, y);
    }
    for (auto &row : t) {
      sort(row.begin(), row.end());
    }
  }
};

fenw1 pp[N];

int qry(int l, int r, int x) {
  int ans = 0;
  for (int he = l; he < r; he++) {
    ans += pp[he].qry(tin[x], tout[x] + 1);
  }
  return ans;
}

// int main() {
//   int tt;
//   cin >> tt;
//   for (int o = 0; o < tt; o++) {
//     cin >> n;
//     for (int i = 0; i < n; i++) {
//       g[i].clear();
//       pp[i].clear();
//     }
//     p[0] = -1;
//     for (int i = 1; i < n; i++) {
//       cin >> p[i];
//       p[i]--;
//     }

//     for (int i = 0; i < n; i++) {
//       cin >> a[i];
//       --a[i];
//     }

//     dfs(0, -1);

//     map<int, int> mp;
//     for (int i = 0; i < n; i++) {
//       mp[a[i]] = n;
//     }
//     for (int i = ti - 1; i >= 0; i--) {
//       nxt[i] = mp[a2[i]];
//       mp[a2[i]] = i;
//     }

//     for (int x = 0; x < n; x++) {
//       pp[h[x]].push(tin[x], nxt[tin[x]]);
//     }
//     for (int i = 0; i < n; i++) {
//       pp[i].build();
//     }

//     int q;
//     cin >> q;

//     int ans = 0;

//     for (int i = 0; i < q; i++) {
//       int x, d;
//       cin >> x >> d;

//       x ^= ans;
//       d ^= ans;
//       x--;

//       // cerr << x << " " << d << "\n";

//       int l = x;
//       int r = min(x + d + 1, n);
//       ans = qry(l, r, x);
//       cout << ans << "\n";
//     }

//     cout << "\n";
//   }
// }

int main() {
  fenw1 f;
  for (int i = 0; i < 100; i++) {
    char typ;
    cin >> typ;
    if (typ == '+') {
      int x, y;
      cin >> x >> y;
      f.push();
    } else if (typ == 'b') {
      f.build();
    } else if (typ == 'q') {
      int l, r;
      cin >> l >> r;
    }
  }
}
