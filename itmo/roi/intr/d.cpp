// semenInRussia 2025
#include <cstdint>
#include <iostream>
#include <map>

using namespace std;

using ll = long long;

map<ll, int> memo;

bool ask(ll i) {
  if (memo.count(i)) {
    return memo[i];
  }
  cout << "? " << (i + 1) << endl;
  int t;
  cin >> t;
  return (memo[i] = t);
}

// 0101010101

int main() {
  ll n;
  cin >> n;

  ll l = 0, r = n;

  memo[0] = 1;
  memo[n - 1] = 0;

  while (r - l > 1) {
    ll m = (l + r) / 2;
    if (ask(l) != ask(m)) {
      r = m;
    } else {
      l = m;
    }
  }

  cout << "! " << (l + 1) << endl;
}
