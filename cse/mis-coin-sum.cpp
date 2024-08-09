// semenInRussia 2024
// https://cses.fi/problemset/task/2183
#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;

const int N = 2e5;
int a[N];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a, a + n);
  ll ans = -1;
  ll x = 0;
  // the sum of checked subset, in this subset every sum before x can
  // be built, so adding a[i], we need to check that we also at least
  // x+1, if we can than add it to subset, otherwise we cant and this
  // is answer
  for (int i = 0; i < n; i++) {
    if (a[i] > x + 1) {
      ans = x + 1;
      break;
    }
    x += a[i];
  }
  // we didn't found the sum we cant, so answer is their sum + 1, we cant do it
  // in any case
  if (ans == -1) {
    ans = 1;
    for (int i = 0; i < n; i++) {
      ans += a[i];
    }
  }

  cout << ans;
}
