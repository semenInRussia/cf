// semenInRussia 2025
#ifndef home
#pragma GCC optimize("Ofast,unroll-loops")
#endif
#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <set>
#include <vector>
#ifndef home
#pragma GCC target("avx2")
#endif

using namespace std;

string s;
int n;
const int inf = 1e9 + 100;

const int N = 2e5 + 100;
int lcp[N], p[N], c[N], _c[N];
int suf[N], pref[N];
pair<int, int> v[N], tmp[N];

//
int sz = 0;

int g[N];

void add(int i, int v = +1) {
  sz += v;
  i++;
  for (; i <= n; i += i & -i) {
    g[i] += v;
  }
}

inline void rem(int i) { add(i, -1); }

int qry(int x) {
  if (x > n) {
    return sz;
  }
  if (x <= 0) {
    return 0;
  }
  int k = 0;
  for (; x > 0; x -= x & -x) {
    k += g[x];
  }
  return k;
}

int kth(int s) {
  if (s < 0) {
    return -1;
  }
  if (s > sz) {
    return -1;
  }
  int k = 0;
  for (int l = __lg(n); l >= 0; l--) {
    if (k + (1 << l) <= n && g[k + (1 << l)] < s) {
      k += (1 << l);
      s -= g[k];
    }
  }
  return k;
}

int lower_bound(int s) {
  s = qry(s) + 1;
  return kth(s);
}

int prev(int s) {
  if (lower_bound(s) == s) {
    return s;
  }
  s = qry(s);
  return kth(s);
}

pair<int, int> st[N];

int f(int l, int r) {
  if (r - l == 1) {
    v[l] = {p[l], l};
    return 0;
  }
  if (r - l <= 1) {
    return 0;
  }

  int m = (l + r) / 2;

  int ans = max(f(l, m), f(m, r));

  // suf : left half
  for (int i = m - 1; i >= l; i--) {
    suf[i] = lcp[i];
    if (i != m - 1) {
      suf[i] = min(suf[i], suf[i + 1]);
    }
  }

  // pref ; right half
  pref[m] = +inf;
  for (int i = m; i < r; i++) {
    pref[i + 1] = min(pref[i], lcp[i]);
  }

  int u = 0;

  for (int i = m; i < r; i++) {
    st[u++] = {pref[i] + p[i], p[i]};
    add(p[i]);
  }
  sort(st, st + u);
  reverse(st, st + u);

  for (int j = l; j < m; j++) {
    auto [a, i] = v[j];
    int b = p[i] - suf[i];
    // delete < a
    while (u > 0 && st[u - 1].first < a) {
      auto [a1, b1] = st[u - 1];
      --u;
      rem(b1);
    }

    auto it = lower_bound(b);
    if (it != -1 && it < a) {
      ans = max(ans, abs(a - it));
    }
  }

  for (int i = 0; i < u; i++) {
    rem(st[i].second);
  }

  u = 0;

  for (int i = m; i < r; i++) {
    st[u++] = {p[i] - pref[i], p[i]};
    add(p[i]);
  }
  sort(st, st + u);

  for (int j = m - 1; j >= l; j--) {
    auto [a, i] = v[j];
    int b = p[i] + suf[i];
    // erase >a
    while (u > 0 && st[u - 1].first > a) {
      auto [a1, b1] = st[u - 1];
      --u;
      rem(b1);
    }

    auto it = prev(b);
    if (it != -1) {
      if (it > a) {
        ans = max(ans, abs(a - it));
      }
    }
  }

  for (int i = 0; i < u; i++) {
    rem(st[i].second);
  }

  merge(v + l, v + m, v + m, v + r, tmp);
  copy(tmp, tmp + r - l, v + l);

  return ans;
}

vector<int> b[N];

// build suffix array
void build() { //
  for (int i = 0; i < n; i++) {
    p[i] = i;
  }
  sort(p, p + n, [](int i, int j) { return s[i] < s[j]; });

  c[p[0]] = 0;
  for (int i = 1; i < n; i++) {
    c[p[i]] = c[p[i - 1]] + (s[p[i]] != s[p[i - 1]]);
  }

  for (int len = 1; len < n && c[p[n - 1]] != n - 1; len *= 2) {
    for (int i = 0; i < n; i++) {
      p[i] = (p[i] - len + n) % n;
    }

    for (int i = 0; i < n; i++) {
      b[c[p[i]]].push_back(p[i]);
    }
    int m = 0;
    for (int i = 0; i < n; i++) {
      for (int x : b[i]) {
        p[m++] = x;
      }
      b[i].clear();
    }

    _c[p[0]] = 0;
    for (int i = 1; i < n; i++) {
      bool add = c[p[i]] != c[p[i - 1]] ||
                 c[(p[i] + len) % n] != c[(p[i - 1] + len) % n];
      _c[p[i]] = _c[p[i - 1]] + add;
    }

    swap(_c, c);
  }

  int k = 0;

  for (int i = 0; i < n - 1; i++) {
    int j = p[c[i] - 1];
    while (s[i + k] == s[j + k]) {
      k++;
    }
    lcp[c[i] - 1] = k;
    if (k > 0) {
      k--;
    }
  }
}

void solve() { //
  cin >> s;
  s += 32;
  n = (int)s.size();
  assert(n - 1 <= 1e5);
  build();

  int ans = f(0, n) * 2;

  cout << ans << "\n";
}

// int main2() {
//   n = 5;
//   add(0);
//   add(1);
//   add(3);
//   for (int x = 0; x < 7; x++) {
//     cerr << x << ": " << lower_bound(x) << "; " << prev(x) << "\n";
//   }
//   return 0;
// }

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
