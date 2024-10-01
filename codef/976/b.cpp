// semenInRussia 2024
#include <cmath>
#include <iostream>
using namespace std;
using ll = long long;

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    ll k;
    cin >> k;
    ll l = 1, r = LLONG_MAX;
    // m - qr(m) >= k
    while (r - l > 1ll) {
      ll m = (r - l) / 2 + l;
      if (m - ll(sqrt(m)) >= k) {
        r = m;
      } else {
        l = m;
      }
    }
    cout << r << '\n';
  }
}

// n - qr(n) = k
//
