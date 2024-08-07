// semenInRussia 2024
#include <iostream>
using namespace std;
using ll = long long;

const int N = 3e5;
int a[N];
ll ops[N];
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> a[i];

    ll ans = 0;
    ops[0] = 0;
    for (int i = 1; i < n; i++) {
      int q = ops[i - 1];
      ll x = a[i - 1];
      ll y = a[i];
      while (x != 1 && x <= y)
        x *= x, q--;
      if (x > y && y == 1) {
        ans = -1;
        break;
      }

      while (x > y)
        y *= y, q++;

      ops[i] = max(q, 0);
      ans += ops[i];
    }
    cout << ans << '\n';
  }
}
