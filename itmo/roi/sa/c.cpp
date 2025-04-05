// semenInRussia 2025
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <string.h>

using namespace std;

const int N = 4e5 + 100;
int c[N], p[N], _c[N], ord[N];
int lcp[N];

char s[N];

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
    lcp[c[i]] = k;
    if (k > 0) {
      --k;
    }
  }

  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    string w;
    cin >> w;

    int l = -1;
    int r = n;

    bool ok = false;

    while (r - l > 1) {
      int m = (l + r) / 2;
      // first >=;
      int t = memcmp(s + p[m], w.data(), w.size());
      ok |= t == 0;
      if (t >= 0) {
        r = m;
      } else {
        l = m;
      }
    }

    cout << (ok ? "Yes\n" : "No\n");
  }
}
