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

const int N = 1e5 + 100;
int lcp[N], p[N], c[N], _c[N];
int suf[N], pref[N];
pair<int, int> v[N], tmp[N];

int64_t f(int l, int r) {
  if (r - l <= 1) {
    return 0;
  }
  int64_t ans = 0;

  for (int i = m - 1; i >= l; --i) {
    suf[i] = (suf[i + 1]);
  }

  return ans;
}

// build suffix array
void build() {
  for (int i = 0; i < n; i++) {
    p[i] = i;
  }
  sort(p, p + n, [](int i, int j) { return s[i] < s[j]; });

  c[p[0]] = 0;
  for (int i = 1; i < n; i++) {
    c[p[i]] = c[p[i - 1]] + (s[p[i]] != s[p[i - 1]]);
  }

  vector<vector<int>> b(n + 1);

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
      ++k;
    }
    lcp[c[i] - 1] = k;
    if (k > 0) {
      --k;
    }
  }
}

bool solve() {
  cin >> s;
  if (s[0] == '0') {
    return false;
  }
  s += 32;
  n = (int)s.size();
  assert(n - 1 <= 1e5);
  build();

  for (int i = 0; i < n; i++) {
    v[i] = {p[i], i};
  }

  cout << ans << "\n";
  return true;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  s.reserve(N);
  while (solve()) {
  }
}
