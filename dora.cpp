// semenInRussia 2024
#include <algorithm>
#include <iostream>
#include <numeric>
using namespace std;
using ll = long long;

const int N = 2e5;
ll c[N];

int main() {
  int T;
  cin >> T;
  while (T--) {
    ll n, a, b;
    cin >> n >> a >> b;
    ll g = gcd(a, b);
    for (int i = 0; i < n; i++) {
      cin >> c[i];
      c[i] = c[i] % g;
    }
    sort(c, c + n);
    ll ans = c[n - 1] - c[0];
    for (int i = 1; i < n; i++) {
      ans = min(ans, c[i - 1] + g - c[i]);
    }
    cout << ans << '\n';
  }
}
