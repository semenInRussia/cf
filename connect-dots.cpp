// semenInRussia 2024
// https://codeforces.com/contest/2020/problem/D
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

#pragma GCC optmize("Ofast,unroll-loops")
#pragma GCC target("avx2")

const int N = 2e5 + 100;

int p[N];

inline int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }

inline bool join(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) {
    return false;
  }
  p[x] = y;
  return true;
}

const int D = 11;

void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    p[i] = i;
  }
  vector f(D, vector(D, vector<pair<int, int>>()));
  for (int i = 0; i < m; i++) {
    int a, d, k;
    cin >> a >> d >> k;
    a--;
    if (k > 0) {
      f[d][a % d].emplace_back(a / d, a / d + k);
    }
  }

  int res = n;
  for (int d = 1; d < D; d++) {
    for (int m = 0; m < d; m++) {
      auto &v = f[d][m];
      sort(v.begin(), v.end());
      int last = -1;
      for (auto [a, b] : v) {
        for (int k = max(a + 1, last + 1); k <= b; k++) {
          res -= join(m + d * (k - 1), m + d * k);
        }
        last = b;
      }
    }
  }
  cout << res << '\n';
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}
