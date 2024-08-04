// semenInRussia 2024
#include <cassert>
#include <iostream>
using namespace std;
using ll = long long;

const int mod = 1e9 + 7, N = 2e5, C = 31, logn = 18;
int p[N], h[N], r[N];

int n;
bool check(int i, int j) {
  if (i < 0 || j < 0 || i > n || j > n)
    return false;

  int a = 1ll * (h[j] - h[i] + mod) * p[n - i] % mod;
  int b = 1ll * (r[j] - r[i] + mod) * p[j] % mod;
  return a == b;
}

int main() {
  string s;
  cin >> s;

  n = int(s.size());
  p[0] = 1;
  for (int i = 1; i <= n + 1; i++)
    p[i] = 1ll * p[i - 1] * C % mod;
  for (int i = 0; i < n; i++)
    s[i] = s[i] - 'a' + 1;

  for (int i = 0; i < n; i++)
    h[i + 1] = (h[i] + 1ll * p[i] * s[i]) % mod;
  for (int i = 0; i < n; i++)
    r[i + 1] = (r[i] + 1ll * p[n - i - 1] * s[i]) % mod;

  ll ans = 0; // don't include one symbol polyndroms
  for (int i = 0; i < n; i++) {
    // i is center (size is odd)
    int l = -1, r = n + 1;
    while (r - l > 1) {
      int m = (r + l) / 2;
      // aba
      // 0123
      if (check(i - m, i + m + 1))
        l = m;
      else
        r = m;
    }
    ans += l;

    // i is left center (size is even)
    // if (check(i - nk, i + nk + 2))
    l = -1, r = n + 1;
    while (r - l > 1) {
      int m = (r + l) / 2;
      if (check(i - m, i + m + 2))
        l = m;
      else
        r = m;
    }
    ans += l + 1;
  }
  cout << ans;
}
