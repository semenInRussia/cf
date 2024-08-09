// semenInRussia 2024
// https://cses.fi/problemset/task/1074
#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;

const int N = 2e5 + 100;
ll b[N];
int a[N];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  sort(a, a + n);
  for (int i = 0; i < n; i++)
    b[i + 1] = b[i] + a[i];

  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ll cur = 0;
    // left: sum: a[i] - a[j]
    cur += 1ll * i * a[i] - b[i];

    // right: sum: a[j] - a[i]
    cur += b[n] - b[i + 1] - 1ll * (n - i - 1) * a[i];

    ans = min(ans, cur);
    if (i == 0)
      ans = cur;
  }
  cout << ans;
}
