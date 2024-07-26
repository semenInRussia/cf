// semenInRussia 2024
// https://codeforces.com/group/jtU6D2hVEi/contest/533277/problem/K

#include <algorithm>
#include <cassert>
#include <iostream>
using namespace std;

const int N = 101, inf = 1e9;
int memo[N][N], a[N];

int f(int l, int r) {
  if (r - l <= 1)
    return +inf;
  int &ans = memo[l][r];
  if (ans != -1)
    return ans;
  if (r - l <= 3) {
    // cout << (l + 1) << " -- " << r << '\n';
    ans = 0;
    for (int i = l + 1; i < r; i++)
      ans += abs(a[i] - a[i - 1]);
    return ans;
  }
  ans = +inf;
  for (int i = l; i < r; i++)
    ans = min(ans, f(l, i) + f(i, r));
  return ans;
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= n; j++)
      memo[i][j] = -1;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a, a + n);
  cout << f(0, n);
}
