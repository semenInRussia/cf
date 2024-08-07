// semenInRussia 2024
// https://codeforces.com/contest/1993/problem/D
#include <algorithm>
#include <iostream>
using namespace std;

const int N = 5e5 + 100, inf = 1.1e9;
int n, k, req;
int f[N], a[N], b[N], dp[N];

bool check(int x) {
  for (int i = 0; i < n; i++)
    f[i] = (a[i] >= x) ? +1 : -1;
  fill(dp, dp + req + 1, -inf);

  dp[0] = 0;
  for (int i = 0; i < n; i++) {
    int len = 1 + (i % k);
    dp[len] = max(dp[len], f[i] + dp[len - 1]);
  }
  return dp[req] > 0;
}

void solve() {
  cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> a[i], b[i] = a[i];

  req = n % k;
  if (req == 0)
    req = k;

  sort(b, b + n);
  int usz = unique(b, b + n) - b;

  int l = 0, r = usz;
  while (r - l > 1) {
    int m = (r + l) / 2;
    if (check(b[m]))
      l = m;
    else
      r = m;
  }
  cout << b[l] << '\n';
}

int main() {
  int T;
  cin >> T;
  while (T--)
    solve();
}
