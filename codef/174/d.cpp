// semenInRussia 2025
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

#ifdef home
#include "C:/Users/hrams/cf/debug.h"
#else
#define debug(...) ;
#endif

using namespace std;

string s;
int n;
int m;
int mid;
int suf;

const int N = 3e5, K = 100;
int cnt[K][N];

// equal prefix=suffix

bool can(int l, int r) {
  int p = min(n - r, l);
  if (p > suf) {
    return false;
  }
  int d = max({m - r, l - m, 0});
  if (!(l <= m && m < r) && d > mid) {
    return false;
  }

  int l1 = n - r;
  int r1 = n - l;
  debug(l, r, l1, r1);
  int l2 = max(l1, l);
  int r2 = min(r1, r);

  vector<int> cur(K);

  for (int c = 0; c < K; c++) {
    cur[c] = cnt[c][r] - cnt[c][l];
    cur[c] -= cnt[c][r1] - cnt[c][l1];
    cur[c] += cnt[c][r2] - cnt[c][l2];
    if (cur[c] < 0 || cur[c] & 1) {
      return false;
    }
  }

  return true;
}

void solve() {
  cin >> s;

  reverse(s.begin(), s.end());

  n = (int)s.size();

  bool ok = true;

  for (int i = 0; i < n; i++) {
    if (s[i] != s[n - i - 1]) {
      ok = false;
    }
  }

  for (auto &c : s) {
    c -= 'a';
  }

  for (int i = 0; i < n; i++) {
    for (int c = 0; c < K; c++) {
      cnt[c][i + 1] = (s[i] == c) + cnt[c][i];
    }
  }

  m = n / 2;

  mid = 0;
  while (mid < m && s[m - mid - 1] == s[mid + m]) {
    mid++;
  }

  suf = 0;
  while (s[suf] == s[n - suf - 1]) {
    suf++;
  }

  if (ok) {
    cout << "0\n";
    return;
  }

  int ans = n;

  for (int i = 0; i < n; i++) {
    int l = i;
    int r = n + 1;
    while (r - l > 1) {
      int m = (l + r) / 2;
      if (can(i, m)) {
        ans = min(m - i, ans);
        r = m;
      } else {
        l = m;
      }
    }
  }

  cout << ans << "\n";
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
