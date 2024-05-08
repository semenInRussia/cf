// Copyright 2024 semenInRussia
// https://codeforces.com/problemset/problem/1969/D
// *1900 #dp #bit #xor

#include <iostream>
using namespace std;
using ll = long long;

const int maxn = 1e6;
ll a[maxn], b[maxn];

struct bits {
  ll c[30], sz = 0;

  bits() { fill(c, c + 30, 0), sz = 0; }
  ll zeros(int i) { return sz - c[i]; } // numbers with zero at ith bit
  ll ones(int i) { return c[i]; }

  void insert(ll x) { sz++, handle(x, +1); }
  void erase(ll x) { sz--, handle(x, -1); }

  void handle(ll x, ll inc) {
    for (ll j = 0; j < 30; j++)
      if ((x >> j) & 1)
        c[j] += inc;
  }
};

void solve() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[i + 1] = a[i] ^ b[i];
  }

  bits l{}, r{};
  for (int i = 0; i <= n; i++)
    r.insert(b[i]);

  ll ans = 0;
  for (int y = 0; y < n; y++) {
    l.insert(b[y]), r.erase(b[y]);
    int i = __lg(a[y]);
    ans += l.zeros(i) * r.zeros(i);
    ans += l.ones(i) * r.ones(i);
  }

  cout << ans << '\n';
}

int main() {
  int tt;
  cin >> tt;
  while (tt--)
    solve();
}
