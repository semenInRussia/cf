// Copyright 2024 semenInRussia

#include <climits>
#include <iostream>
#include <vector>

using namespace std;

using ll = __int128;
const ll mod = 998'244'353;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n), b(n + 1, 0);
  for (int i = 0; i < n; i++) {
    long long x;
    cin >> x;
    a[i] = x;
    b[i + 1] = (a[i] + b[i]) % mod;
  }

  ll ans = 0;
  // find all f(i, j)
  for (ll j = 1; j < (ll)n; j++) {
    ll sm = b[j];        // 10^14
    ll x = a[j], pw = 1; // 10^9
    while (x)
      pw = pw * 10ll, x /= 10;
    ans = (ans + sm * pw) % mod;
    ans = (ans + a[j] * j) % mod;
  }

  cout << (long long)ans;
}
