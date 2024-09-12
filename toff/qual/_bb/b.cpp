// semenInRussia 2024
#include <algorithm>
#include <cassert>
#include <iostream>
#include <utility>
using namespace std;
using ll = long long;

#pragma GCC optimize("unroll-loops,Ofast")

int main() {
  ll a, b;
  cin >> a >> b;
  if (a > b) {
    swap(a, b);
  }
  ll ans = 0;
  while (a > 1) {
    ll k = (b + a - 1) / a - 1;
    b -= a * k;
    ans += k;
    swap(a, b);
    if (a == b) {
      ans += 1;
      a = b = 0;
    }
  }
  ans += b;
  cout << ans;
}
