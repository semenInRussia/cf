// semenInRussia 2024
// https://codeforces.com/problemset/problem/1992/G
#include <iostream>
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 5001;
int C[maxn][maxn];
void solve() {
  int n;
  cin >> n;
  int ans = 0;
  int sm = 0;
  for (int len = 0; len <= n; len++) {
    int z = len + 1;
    if (2 * len >= n) {
      // all numbers are <= z
      z += len;
      ans = (ans + (1ll * C[n][len] * z % mod)) % mod;
      continue;
    }
    for (int o = 0; o <= len; o++) {
      int n1 = o + z - 1;
      int n2 = n - n1 - 1;
      int d = (1ll * C[n1][o] * C[n2][len - o]) % mod;
      ans += 1ll * d * (o + z) % mod;
      ans %= mod;
    }
  }
  cout << ans << '\n';
}

int main() {
  // C[n][k] - to do comb (|comb| = k) from 1..n
  for (int i = 0; i < maxn; i++)
    C[i][i] = C[i][0] = 1;
  for (int n = 0; n < maxn; n++)
    for (int k = 1; k < n; k++)
      C[n][k] = (C[n - 1][k - 1] + C[n - 1][k]) % mod;

  int T;
  cin >> T;
  while (T--)
    solve();
}
