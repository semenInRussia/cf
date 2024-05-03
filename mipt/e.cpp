// Copyright 2024 semenInRussia

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
using ull = unsigned long long;

ll pow2(ll k, int mod) {
  int p = 2;
  ll ans = 1;
  while (k > 0) {
    if (k & 1)
      ans = (ans * p) % mod;
    p = (p * p) % mod;
    k >>= 1;
  }

  return ans;
}

int main() {
  ll n;
  int m;
  cin >> n >> m;
  ll ans = (5 * pow2(n - 1, m) - 4) % m;
  cout << (ans < 0 ? ans + m : ans) << '\n';
}
