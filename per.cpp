// semenInRussia 2024
#include <cmath>
#include <iostream>
using namespace std;
using ll = long long;

ll msqrt(ll x) { // first a: a*a >= x
  ll root = sqrt(x);
  if (root * root == x)
    return root;
  return root + 1;
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    ll r, ans = 0;
    cin >> r;
    for (ll y = 0; y <= r; y++) {
      ll a = msqrt(r * r - y * y);
      ll b = msqrt((r + 1) * (r + 1) - y * y);
      ans += 4 * max(0ll, b - a);
    }
    cout << (ans - 4) << '\n';
  }
}
