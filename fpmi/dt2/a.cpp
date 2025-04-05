// semenInRussia 2025
#pragma GCC optimize("Ofast,unroll-loops")
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <string.h>
#pragma GCC target("avx2")

using namespace std;

const int N = 1 << 19;
const int64_t infll = 1e17 + 5;
int64_t b[N], dp[N];
int a[N];
pair<pair<int, int>, int> qs[N];

int64_t t[N * 2];

void upd(int j, int64_t v, int x = 0, int l = 0, int r = N) {
  if (r - l == 1) {
    t[x] = v;
    return;
  }

  int m = (l + r) / 2;
  if (j < m) {
    upd(j, v, 2 * x + 1, l, m);
  } else {
    upd(j, v, 2 * x + 2, m, r);
  }
  t[x] = min(t[2 * x + 1], t[2 * x + 2]);
}

int64_t qry(int ql, int qr, int x = 0, int l = 0, int r = N) {
  if (l >= qr || r <= ql) {
    return +infll;
  }
  if (ql <= l && r <= qr) {
    return t[x];
  }

  int m = (l + r) / 2;
  return min(qry(ql, qr, 2 * x + 1, l, m), qry(ql, qr, 2 * x + 2, m, r));
}

int n, m;

void build() {
  for (int i = 0; i < N; i++) {
    t[i] = +infll;
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    b[i + 1] = b[i] + a[i];
  }
  for (int i = 1; i <= n; i++) {
    dp[i] = +infll;
  }

  build();

  for (int i = 0; i < m; i++) {
    int l, r, c;
    cin >> l >> r >> c;
    l--;
    qs[i] = {{l, r}, c};
  }

  sort(qs, qs + m, [](auto a, auto b) {
    return (a.first.second < b.first.second) ||
           (a.first.second == b.first.second && a < b);
  });

  for (int i = 0; i < m; i++) {
    auto [l, r] = qs[i].first;
    int c = qs[i].second;
    dp[r] = min(dp[r], qry(l, r) + c - b[l]);
    upd(r, dp[r] + b[r]);
  }

  cout << (dp[n] >= +infll ? -1 : dp[n]) << "\n";
}
