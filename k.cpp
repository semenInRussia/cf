// semenInRussia 2024
#include <iostream>
using namespace std;

const int C = 31, N = 5e6 + 100, mod = 1e9 + 123;
int h[N], p[N];

int main() {
  string s;
  cin >> s;
  int n = int(s.size());
  p[0] = 1;
  for (int i = 1; i <= n; i++)
    p[i] = (1ll * p[i - 1] * C) % mod;
  for (char &ch : s)
    ch = ch - 'a' + 1;
  for (int i = 0; i < n; i++)
    h[i + 1] = (h[i] + 1ll * p[i] * s[i]) % mod;

  int ans = 0;
  for (int k = 1; k <= n; k++) {
    if (n % k)
      continue;
    int o = 1ll * ((h[k] - h[0] + mod) % mod) * p[n] % mod;
    bool ok = 1;
    for (int i = k; i < n && ok; i += k) {
      int cur = 1ll * ((h[i + k] - h[i] + mod) % mod) * p[n - i] % mod;
      if (cur != o)
        ok = 0;
    }
    if (ok) {
      ans = k;
      break;
    }
  }
  cout << ans;
}
