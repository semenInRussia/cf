// Copyright 2024 semenInRussia

#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
const ll mod = (ll)1e8;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto &x : a)
    cin >> x;
  ll f1 = 0; // all f(1, x)
  for (int i = 1; i < n; i++)
    f1 += (a[0] + a[i]) % mod;

  ll ans = f1;
  for (int i = 1; i < n; i++) {
  }

  cout << ans;
}
