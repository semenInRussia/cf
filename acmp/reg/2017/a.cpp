// semenInRussia 2024
// https://acmp.ru/asp/do/index.asp?main=topic&id_course=3&id_section=24&id_topic=181
#include <iostream>
using namespace std;
using ll = long long;

int n, k, x, y;

ll count(int f) {
  int d = f / k;
  int o = f - d;
  return 1ll * d * x + 1ll * o * y;
}

int main() {
  cin >> n >> k >> x >> y;

  // one podjezd
  ll p = count(n);

  int q;
  cin >> q;

  while (q--) {
    ll a;
    cin >> a;
    a %= p; // remove rooms from previous podjeds
    if (a == 0) {
      a += p;
    }
    int l = 0, r = n + 1;
    // first is >=
    while (r - l > 1) {
      int m = (r + l) / 2;
      if (count(m) >= a) {
        r = m;
      } else {
        l = m;
      }
    }
    cout << r << '\n';
  }
}
