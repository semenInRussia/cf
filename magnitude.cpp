// https://codeforces.com/problemset/problem/1984/C2 or C1
#include <cmath>
#include <iostream>
#include <map>
using namespace std;
using ll = long long;
using pil = pair<int, ll>;

const int maxn = 3e5, mod = 998244353;
ll a[maxn];

struct mi {
  int v;
  mi(ll _v = 0) : v(_v % mod) {}
};
void operator*=(mi &a, int k) { a = mi(1ll * a.v * k); }
void operator+=(mi &a, mi b) { a = mi(a.v + b.v); }

map<pil, mi> lazy;
ll mn[maxn], mx[maxn];
mi f(int i, ll x) {
  if (lazy.count({i, x}))
    return lazy[{i, x}];
  if (i == 0)
    return lazy[{i, x}] = (a[i] == x) + (abs(a[i]) == x);
  if (x < mn[i] || x > mx[i])
    return lazy[{i, x}] = 0;

  mi ans = f(i - 1, x - a[i]);
  if (x >= 0)
    ans *= 2;
  if (x > 0)
    ans += f(i - 1, -x - a[i]);
  return lazy[{i, x}] = ans;
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    lazy.clear();
    for (int i = 0; i < n; i++)
      cin >> a[i];

    mx[0] = abs(a[0]), mn[0] = a[0];
    for (int i = 1; i < n; i++) {
      mx[i] = max(mx[i - 1] + a[i], abs(mn[i - 1] + a[i]));
      mn[i] = mn[i - 1] + a[i];
    }
    cout << f(n - 1, mx[n - 1]).v << '\n';
  }
}
