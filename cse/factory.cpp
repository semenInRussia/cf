// semenInRussia 2024
// https://cses.fi/problemset/task/1620
#include <iostream>
using ll = long long;
using namespace std;

const int N = 2e5;
int a[N];
int main() {
  int n;
  ll t;
  cin >> n >> t;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  ll l = -1, r = 1e18 + 100;
  while (r - l > 1) {
    ll m = (r - l) / 2 + l;

    ll cur = 0;
    for (int i = 0; i < n && cur < t; i++) {
      cur += m / a[i];
    }

    if (cur >= t)
      r = m;
    else
      l = m;
  }
  cout << r;
}
