// semenInRussia 2024
#include <iostream>
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7, C = 31;
const int maxn = 1e6 + 100;
ll h[maxn], r[maxn], p[maxn];
int n;
inline ll modulo(ll x) {
  x %= mod;
  x += (x < 0) * mod;
  return x;
}

bool check(int i, int j) { // that not polyndrom
  ll a = modulo(h[j + 1] - h[i]) * p[n - i] % mod;
  ll b = modulo(r[j + 1] - r[i]) * p[j] % mod;
  return a != b;
}

int main() {
  p[0] = 1;
  for (int i = 0; i + 1 < maxn; i++)
    p[i + 1] = (p[i] * C) % mod;

  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    n = (int)s.size();
    for (int i = 0; i < n; i++) {
      ll x = s[i] - 'a' + 1;
      h[i + 1] = (h[i] + p[i] * x) % mod;
      r[i + 1] = (r[i] + p[n - i] * x) % mod;
    }

    if (check(0, n - 1)) {
      cout << "YES\n1\n" << s << '\n';
      continue;
    }

    int ans = 0;
    for (int i = 1; i < n - 1; i++)
      if (check(0, i) && check(i + 1, n - 1))
        ans = i;

    if (ans)
      cout << "YES\n2\n"
           << s.substr(0, ans + 1) << ' ' << s.substr(ans + 1) << '\n';
    else
      cout << "NO\n";
  }
}
