// semenInRussia 2024
#include <cassert>
#include <iostream>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 2e5, C = 31;
const int mod = 1e9 + 7;

int p[N], s[N], r[N];
ull tp[N], th[N], tr[N];

struct hstring {
  int h1, len;
  ull h2;
  hstring(ll _h, ull _h2, int _len, int mult = 1)
      : len(_len), h1((_h * mult) % mod), h2(_h2) {
    h1 += mod * (h1 < 0);
  }

  void add_suffix(hstring suf) {
    h1 = (h1 + 1ll * suf.h1 * p[len]) % mod;
    h2 = h2 + suf.h2 * tp[len];
    len += suf.len;
  }

  bool operator==(hstring b) {
    return len == b.len && b.h1 == h1 && b.h2 == h2;
  }
};
void operator+=(hstring &s, hstring suf) { s.add_suffix(suf); }

int h[N];

int main() {
  string str;
  cin >> str;

  int n = int(str.size());
  for (int i = 0; i < n; i++)
    s[i] = int(str[i] - 'a' + 1);

  tp[0] = p[0] = 1;
  for (int i = 1; i <= n + 1; i++)
    p[i] = 1ll * p[i - 1] * C % mod;
  for (int i = 1; i <= n + 1; i++)
    tp[i] = tp[i - 1] * C;

  for (int i = 0; i < n; i++)
    h[i + 1] = (h[i] + 1ll * s[i] * p[i]) % mod;
  for (int i = 0; i < n; i++)
    r[i + 1] = (r[i] + 1ll * s[i] * p[n - i - 1]) % mod;

  for (int i = 0; i < n; i++)
    th[i + 1] = th[i] + tp[i] * s[i];
  for (int i = 0; i < n; i++)
    tr[i + 1] = tr[i] + tp[n - i - 1] * s[i];

  int ans = -1;

  for (int i = n - 1; i >= 0; i--) {
    hstring a = {h[n] - h[i], (th[n] - th[i]) * tp[n - i], n - i, p[n - i]};
    a += {h[i], th[i] * tp[n], i, p[n]};

    hstring b = {r[i], tr[i] * tp[i], i, p[i]};
    b += {r[n] - r[i], tp[n] * (tr[n] - tr[i]), n - i, p[n]};

    if (a == b)
      ans = n - i;
  }
  cout << ans;
}
