// semenInRussia 2024
// https://codeforces.com/problemset/problem/1976/D?lang=en
#include <algorithm>
#include <cassert>
#include <iostream>
using namespace std;
const int N = 3e5, K = 25, inf = 1e9;
using ll = long long;
int a[N], o[N], st[N][K];
string s;

int qry(int l, int r) {
  if (r - l <= 0)
    return -inf;
  int k = __lg(r - l);
  return max(st[l][k], st[r - (1 << k)][k]);
}

void solve() {
  cin >> s;
  int n = (int)s.size();
  a[0] = 0;
  for (int i = 0; i < n; i++)
    a[i + 1] = a[i] + (s[i] == '(') - (s[i] == ')');
  n++;
  assert(a[n - 1] == 0);
  // p[l] - (p[i] - p[l])
  // 2 p[l] - p[i] >= 0

  // sparse_table
  for (int i = 0; i < n; i++)
    st[i][0] = a[i];
  for (int k = 0; k < K; k++)
    for (int i = 0; (i + (2 << k)) <= n; i++)
      st[i][k + 1] = max(st[i][k], st[i + (1 << k)][k]);

  for (int i = 0; i < n; i++)
    o[i] = i;
  stable_sort(o, o + n, [](int i, int j) { return a[i] < a[j]; });
  int L = 0, R = 1;
  ll ans = 0;
  while (L < n) {
    while (R < n && a[o[R]] == a[o[L]])
      R++;
    // 2 p[l] >= p[i]
    // i: [l, r)
    int r = L;
    for (int l = L; l < R; l++) {
      r = max(r, l);
      while (r + 1 < R && 2 * a[o[l]] >= qry(o[l], o[r + 1]))
        r++;
      ans += r - l;
    }
    L = R;
  }
  cout << ans << '\n'; // dont include whole expression
}

int main() {
  int T;
  cin >> T;
  while (T--)
    solve();
}
