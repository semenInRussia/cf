#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int add(int x, int y) {
  x += y;
  if (x >= MOD)
    x -= MOD;
  return x;
}

int mul(int x, int y) { return x * 1LL * y % MOD; }

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  int s = accumulate(a.begin(), a.end(), 0);
  vector<int> dp(s + 1);
  dp[0] = 1;
  for (int i = 0; i < n; ++i)
    for (int j = s - a[i]; j >= 0; --j)
      dp[j + a[i]] = add(dp[j + a[i]], dp[j]);
  int ans = 0;
  for (int j = 0; j <= s; ++j)
    ans = add(ans, mul((j + 1) / 2, dp[j]));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < a[i]; ++j)
      ans = add(ans, mul(a[i] - (a[i] + j + 1) / 2, dp[j]));
  cout << ans << '\n';
}
