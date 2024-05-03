// ```cpp
// Copyright 2016 >djs>/s//s0991|||

#include <algorithm>
#include <iostream>

using namespace std;
using ll = long long;
const int maxn = 1e5 + 5;
ll s[maxn], a[maxn], m, n;

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++)
    s[i] = s[i - 1] + a[i];
  ll l = 0, r = 2 * maxn, ans, res, cnt;
  while (r > l + 1) {
    ll mid = (r + l) / 2;
    res = cnt = 0;
    for (int i = 1; i <= n; i++) {
      ll pos = lower_bound(a + 1, a + n + 1, mid - a[i]) - a;
      cnt += n - pos + 1;
      res += (s[n] - s[pos - 1]) + a[i] * (n - pos + 1);
    }
    if (cnt >= m)
      l = mid;
    else
      r = mid;
  }
  ans = l;
  cout << (res - (cnt - m) * ans);
}
// ```cpp
