// semenInRussia 2024
#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;

const int maxn = 5060;
int a[maxn], cnt[maxn], n;
int memo[maxn][maxn];
int f(int x, int i) {
  // either eat i-th or not
  if (i == n)
    return 0;
  if (memo[x][i] >= 0)
    return memo[x][i];
  int ret = f(x + 1, i + 1);
  if (cnt[i] <= x)
    ret = max(ret, 1 + f(x - cnt[i], i + 1));
  return memo[x][i] = ret;
}
void solve() {
  cin >> n;
  fill(cnt, cnt + n + 1, 0);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++)
      memo[i][j] = -1;
  // remove zeroes
  int j = 0;
  for (int i = 0; i <= n; i++)
    if (cnt[i] != 0)
      cnt[j++] = cnt[i];
  n = j;
  cout << (n - f(0, 0)) << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  int tt;
  cin >> tt;
  while (tt--)
    solve();
}
