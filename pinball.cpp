// semenInRussia 2024
// https://codeforces.com/contest/1937/problem/D?lang=ru
#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iostream>
using namespace std;

const int N = 6e5;

int a[N];
int n;
string s;

int64_t lef[N], rig[N];
int b[N];
int64_t ans[N];

int ones(int l, int r) { return b[r] - b[l]; }
int zeros(int l, int r) { return (r - l) - ones(l, r); }

int prv(int j, int k) {
  int l = -1;
  int r = j + 1;

  // first m; ones() >= k

  while (r - l > 1) {
    int m = (r + l) / 2;
    if (ones(j - m, j) >= k) {
      r = m;
    } else {
      l = m;
    }
  }

  return j - r;
}

int nxt(int j, int k) {
  int l = -1;
  int r = n - j;

  // first m; zeros() >= k

  while (r - l > 1) {
    int m = (r + l) / 2;
    if (zeros(j + 1, j + m + 1) >= k) {
      r = m;
    } else {
      l = m;
    }
  }

  return j + r;
}

void solve() {
  cin >> n >> s;

  s.insert(s.begin(), '>');
  s.push_back('<');

  n += 2;

  b[0] = 0;
  for (int i = 0; i < n; i++) {
    b[i + 1] = b[i] + (s[i] == '>');
  }

  for (int i = 0; i < n; i++) {
    a[i] = 0;
    if (s[i] == '<') {
      a[i] = i;
    }
  }

  lef[0] = 0;
  for (int i = 0; i < n; i++) {
    lef[i + 1] = lef[i] + a[i];
  }

  for (int i = 0; i < n; i++) {
    a[i] = 0;
    if (s[i] == '>') {
      a[i] = i;
    }
  }

  rig[0] = 0;
  for (int i = 0; i < n; i++) {
    rig[i + 1] = rig[i] + a[i];
  }

  for (int i = 1; i + 1 < n; i++) {
    int k1 = ones(0, i);
    int k2 = zeros(i + 1, n);

    assert(k1 > 0 && k2 > 0);

    int k = min(k1, k2);

    if (s[i] == '<') {
      if (k1 > k2) {
        int jl = prv(i, k);
        int jr = nxt(i, k);
        auto L = (rig[i] - rig[jl]) * 2;
        auto R = (lef[jr + 1] - lef[i + 1]) * 2 - jr + i;
        ans[i] = R - L;
      } else {
        int jl = prv(i, k);
        int jr = nxt(i, k - 1);
        auto L = (rig[i] - rig[jl]) * 2 - jl;
        auto R = (lef[jr + 1] - lef[i + 1]) * 2 + i;
        ans[i] = R - L;
      }
    } else {
      if (k1 < k2) {
        int jl = prv(i, k);
        int jr = nxt(i, k);
        auto L = (rig[i] - rig[jl]) * 2 - lef[jl] + i;
        auto R = (lef[jr + 1] - lef[i + 1]) * 2;
        ans[i] = R - L;
      } else {
        int jl = prv(i, k - 1);
        int jr = nxt(i, k);
        auto L = (rig[i] - rig[jl]) * 2 + i;
        auto R = (lef[jr + 1] - lef[i + 1]) * 2 - jr;
        ans[i] = R - L;
      }
    }
  }

  for (int i = 1; i + 1 < n; i++) {
    cout << ans[i] << " ";
  }
  cout << '\n';
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
