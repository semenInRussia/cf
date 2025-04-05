// semenInRussia 2025
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <string.h>

using namespace std;

const int N = 4e5 + 100;
int c[N], p[N], _c[N], ord[N];
int lcp[N];
pair<int, int> b[N];

char s[N];

const int L = 20;
int st[N][L];

const int inf = 1e9 + 100;

int qry(int l, int r) {
  if (r - l <= 0) {
    return inf;
  }
  int k = __lg(r - l);
  return min(st[l][k], st[r - (1 << k)][k]);
}

int main() {
  cin >> s;
  int n = strlen(s) + 1;

  for (int i = 0; i < n; i++) {
    p[i] = i;
  }

  sort(p, p + n, [&](int i, int j) { return s[i] < s[j]; });

  c[p[0]] = 0;
  for (int i = 1; i < n; i++) {
    c[p[i]] = c[p[i - 1]] + (s[p[i]] != s[p[i - 1]]);
  }

  for (int len = 1; len < n; len *= 2) {
    for (int i = 0; i < n; i++) {
      p[i] = (p[i] - len + n) % n;
    }

    stable_sort(p, p + n, [&](int i, int j) { return c[i] < c[j]; });

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
      ++k;
    }
    lcp[c[i] - 1] = k;
    if (k > 0) {
      --k;
    }
  }

  for (int i = 0; i < n; i++) {
    st[i][0] = lcp[i];
  }
  for (int l = 0; l + 1 < L; l++) {
    for (int i = 0; i + (2 << l) <= n; i++) {
      st[i][l + 1] = min(st[i][l], st[i + (1 << l)][l]);
    }
  }

  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> b[i].first >> b[i].second;
    --b[i].first;
  }

  sort(b, b + m, [](auto x, auto y) {
    auto [l1, r1] = x;
    auto [l2, r2] = y;
    int g = qry(min(c[l1], c[l2]), max(c[l1], c[l2]));
    int len1 = r1 - l1;
    int len2 = r2 - l2;
    if (g >= min(len1, len2)) {
      return len1 < len2 || (len1 == len2 && l1 < l2);
    }
    return s[l1 + g] < s[l2 + g];
  });

  for (int i = 0; i < m; i++) {
    auto [l, r] = b[i];
    cout << (l + 1) << " " << r << "\n";
  }
}
