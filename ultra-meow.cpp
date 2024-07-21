// semenInRussia 2024
// https://codeforces.com/problemset/problem/1992/G
#include <iostream>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
const int maxn = 5001;
ll C[maxn][maxn];
void solve() {
  int n;
  cin >> n;
  ll ans = 0;
  for (int len = 0; len <= n; len++) {
    // z = len+1
    // len=1, (vars to do len)*z - (vars when have any of <= z)*z +
    // (vars have 1 <=z)*(z+1) + (vars have 2 <=z)*(z+2)
    int z = len + 1;
    ll old = ans;
    if (2 * len >= n) {
      // all numbers <= z
      z += len;
      ans = (ans + (1ll * C[n][len] * z % mod)) % mod;
      cout << len << ": " << (ans - old) << '\n';
      continue;
    }
    for (int o = 0; o <= len; o++) {
      int n1 = o + len;
      int d = (1ll * C[n1][o] * C[n - n1 - 1][len - o]) % mod;
      ans += 1ll * d * (o + z) % mod;
      ans %= mod;
    }
    cout << len << ": " << (ans - old) << '\n';
  }
  cout << (ans % mod) << '\n';
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
