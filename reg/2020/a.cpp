// semenInRussia 2025
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  cout.tie(0);
  ll k;
  cin >> k;
  ll a, x;
  cin >> a >> x;
  ll b, y;
  cin >> b >> y;
  // ll ans1 = (k >= a ? (k - a - b >= 0 ? (k - a) ))
  ll ans1 = max(0ll, (k - a) * x) + max(0ll, (k - a - b) * y);
  ll ans2 = max(0ll, (k - b) * y) + max(0ll, (k - a - b) * x);
  cout << max(ans1, ans2);
}
