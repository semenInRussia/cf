#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;
typedef long long ll;
const int N = 5005, M = 200010;

ll ver[M], edge[M], cost[M], Next[M], head[N];
ll d[N], incf[N], pre[N], v[N];
ll n, k, tot, s, t, maxflow, ans;

void add(int x, int y, int z, ll c) {
  ver[++tot] = y;
  edge[tot] = z;
  cost[tot] = c;

  Next[tot] = head[x];
  head[x] = tot;
  ver[++tot] = x;
  edge[tot] = 0;
  cost[tot] = -c;

  Next[tot] = head[y];
  head[y] = tot;
}

bool spfa() {
  queue<int> q;
  memset(d, 0x3f, sizeof(d));
  memset(v, 0, sizeof(v));

  q.push(s);
  d[s] = 0;
  v[s] = 1;
  incf[s] = 1ll << 62;

  while (q.size()) {
    int x = q.front();
    v[x] = 0;
    q.pop();
    for (int i = head[x]; i; i = Next[i]) {
      if (!edge[i]) {
        continue;
      }
      int y = ver[i];
      if (d[y] > d[x] + cost[i]) {
        d[y] = d[x] + cost[i];
        incf[y] = min(incf[x], edge[i]);
        pre[y] = i;
        if (!v[y]) {
          v[y] = 1;
          q.push(y);
        }
      }
    }
  }
  if (d[t] == 0x3f3f3f3f3f3f3f3f)
    return false;
  return true;
}

void update() {
  int x = t;
  while (x != s) {
    int i = pre[x];
    edge[i] -= incf[t];
    edge[i ^ 1] += incf[t];
    x = ver[i ^ 1];
  }
  maxflow += incf[t];
  ans += d[t] * incf[t];
}

int match[55][55];

void solve() {
  cin >> n >> k;

  memset(head, 0, sizeof(head));
  memset(pre, 0, sizeof(pre));
  memset(incf, 0, sizeof(incf));

  tot = 1;
  ans = 0;

  vector<ll> a(n), b(n), c(n);

  auto f = [&](int i, ll x) { return a[i] * x * x + b[i] * x + c[i]; };

  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i] >> c[i];

    int l = 1, r = k;
    int pos = 1;
    while (l < r) {
      int m1 = (2 * l + r) / 3;
      int m2 = (l + 2 * r + 2) / 3;
      if (f(i, m1) > f(i, m2)) {
        l = m1 + 1;
      } else {
        r = m2 - 1;
      }
    }

    if (f(i, l) < f(i, r)) {
      pos = l;
    } else {
      pos = r;
    }

    l = pos - 1;
    r = pos + 1;

    match[i][1] = pos;
    for (int j = 2; j <= n; j++) {
      if (f(i, l) < f(i, r)) {
        if (l >= 1 && l <= k) {
          match[i][j] = l;
          l--;
        } else {
          match[i][j] = r;
          r++;
        }
      } else {
        if (r >= 1 && r <= k) {
          match[i][j] = r;
          r++;
        } else {
          match[i][j] = l;
          l--;
        }
      }
    }
  }

  unordered_map<int, int> mp;
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (!mp[match[i][j]]) {
        mp[match[i][j]] = ++cnt;
      }
    }
  }

  s = 0;
  t = n + cnt + 1;

  for (int i = 1; i <= n; i++) {
    add(s, i + cnt, 1, 0);
    for (int j = 1; j <= n; j++) {
      add(i + cnt, mp[match[i][j]], 1, f(i, match[i][j]));
    }
  }

  for (int i = 0; i < cnt; i++) {
    add(i, t, 1, 0);
  }

  for (int i = 0; i < n; i++) {
    spfa();
    update();
    cout << ans << ' ';
  }
  cout << "\n";
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    solve();
  }

  return 0;
}
