// semenInRussia 2025
#include <algorithm>
#include <cstdint>
#include <iostream>

using namespace std;

const int L = 20;
const int N = 4e5 + 100;
int lcp[N], ans[N], p[N], c[N], _c[N], st[N][L];

int qry(int l, int r) {
  int k = __lg(r - l);
  return min(st[l][k], st[r - (1 << k)][k]);
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
#ifndef home
  freopen("periodic.in", "r", stdin);
  freopen("periodic.out", "w", stdout);
#endif
  string s;
  cin >> s;
  s += '$';

  int n = (int)s.size();

  // 1. suffix array
  for (int i = 0; i < n; i++) {
    p[i] = i;
  }
  sort(p, p + n, [&](int i, int j) { return s[i] < s[j]; });
  c[p[0]] = 0;
  for (int i = 1; i < n; i++) {
    c[p[i]] = c[p[i - 1]] + (s[p[i - 1]] != s[p[i]]);
  }

  for (int len = 1; len < n && c[p[n - 1]] != n - 1; len *= 2) {
    for (int i = 0; i < n; i++) {
      p[i] = (p[i] + n - len) % n;
    }

    stable_sort(p, p + n, [](int i, int j) { return c[i] < c[j]; });

    _c[p[0]] = 0;
    for (int i = 1; i < n; i++) {
      bool add = c[p[i]] != c[p[i - 1]] ||
                 c[(p[i] + len) % n] != c[(p[i - 1] + len) % n];
      _c[p[i]] = _c[p[i - 1]] + add;
    }

    swap(_c, c);
  }

  // 2. lcp
  int k = 0;
  for (int i = 0; i < n - 1; i++) {
    int j = p[c[i] - 1];
    while (s[j + k] == s[i + k]) {
      ++k;
    }
    lcp[c[i] - 1] = k;
    if (k > 0) {
      --k;
    }
  }

  // 3. sparse table
  for (int i = 0; i < n; i++) {
    st[i][0] = lcp[i];
  }
  for (int l = 0; l + 1 < L; l++) {
    for (int i = 0; i + (2 << l) <= n; i++) {
      st[i][l + 1] = min(st[i][l], st[i + (1 << l)][l]);
    }
  }

  // 4. easy
  for (int i = 0; i < n; i++) {
    ans[i] = 1;
  }

  for (int k = 1; k <= n; k++) {
    int l = c[0];
    int r = c[0];
    for (int i = k; i < n; i += k) {
      if (l == r || qry(l, r) >= k) {
        ans[i - 1] = max(ans[i - 1], i / k);
      }
      l = min(l, c[i]);
      r = max(r, c[i]);
    }
  }

  for (int i = 0; i < n - 1; i++) {
    cout << ans[i] << " ";
  }
}
