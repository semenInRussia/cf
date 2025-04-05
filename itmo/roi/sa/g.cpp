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
  if (r - l == 0) {
    return +inf;
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

  int64_t ans = 1ll * n * (n - 1) / 2;

  for (int i = 1; i < n; i++) {
    int x = lcp[i];
    // (find last <) +  1
    int l = 0;
    int r = i + 1;
    while (r - l > 1) {
      int m = (l + r) / 2;
      if (m == i || qry(m, i) >= lcp[i]) {
        r = m;
      } else {
        l = m;
      }
    }

    int L = r;

    l = i - 1;
    r = n;

    while (r - l > 1) {
      int m = (l + r) / 2;
      if (i == m || qry(i + 1, m + 1) > lcp[i]) {
        l = m;
      } else {
        r = m;
      }
    }

    int R = l;

    // (find first <=)
    int64_t w = 1ll * (i - L + 1) * (R - i + 1);
    // cerr << i << ": " << w << ":" << L << "; " << R << "\n";
    ans += w * x;
  }

  cout << ans;
}
