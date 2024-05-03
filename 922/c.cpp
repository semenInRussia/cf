// https://codeforces.com/contest/922/c

using namespace std;

using ll = long long;

#include <bitset>
#include <iostream>
#include <vector>

bool bat(ll n, size_t i) { return (n << i) & 1; }
ll ll_abs(ll x) { return (x > 0) ? x : -x; }

void solve() {
  ll a, b, r;
  cin >> a >> b >> r;

  bitset<64> x;

  if (a > b)
    swap(a, b);

  ll a0 = a, b0 = b;
  bool used = 0;

  for (size_t i = 0; i < 63; i++) {
    bitset<64> prev = x;

    if ((a & 1) == (b & 1)) {
    } else if (!(a & 1)) { // 1 0
      x[i] = !used;
      used = 1;
    }
    
    if (x.to_ullong() > r) {
      x = prev;
      break;
    }

    a >>= 1;
    b >>= 1;
  }

  ll k = x.to_ullong();
  a = a0;
  b = b0;

  // cout << "K: " << k << endl;

  cout << ll_abs((a ^ k) - (b ^ k)) << endl;
}

int main() {
  size_t t;
  cin >> t;

  while (t--)
    solve();

  return 0;
}
