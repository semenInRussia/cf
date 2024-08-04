// semenInRussia 2024
#include <iostream>
using namespace std;

const int N = 2e5, C = 31, mod = 1e9 + 7;
int p[N], h[N];

int main() {
  string s;
  cin >> s;
  int n = int(s.size());
  for (int i = 0; i < n; i++) {
    s[i] = s[i] - 'a' + 1;
    p[i] = i ? (1ll * p[i - 1] * C % mod) : 1;
    h[i + 1] = (h[i] + 1ll * p[i] * s[i]) % mod;
  }
  p[n] = 1ll * p[n - 1] * C % mod;
  int m;
  cin >> m;
  while (m--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a--, c--;

    int f = 1ll * (h[b] - h[a] + mod) * p[n - a] % mod;
    if (f < 0)
      f += mod;
    int g = 1ll * (h[d] - h[c] + mod) * p[n - c] % mod;
    if (g < 0)
      g += mod;

    cout << ((f == g) ? "Yes\n" : "No\n");
  }
}
