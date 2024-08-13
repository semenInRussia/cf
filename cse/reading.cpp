// semenInRussia 2024
// https://cses.fi/problemset/task/1631
#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;

const int N = 2e5;
int a[N];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  ll t1 = 0;
  // algo:
  // (A) reads first, (B) reads other
  for (int i = 0; i < n - 1; i++)
    t1 += a[i];
  if (t1 <= a[n - 1])
    cout << 2ll * a[n - 1];
  else {
    ll ans = 0;
    for (int i = 0; i < n; i++)
      ans += a[i];
    cout << ans;
  }
}
