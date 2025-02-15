// semenInRussia 2025
#include <cassert>
#include <cstdint>
#include <iostream>

using namespace std;

const int N = 105;
int a[N];

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    assert(i == 0 || a[i] == a[i - 1]);
  }

  int64_t ans = 0;

  for (int j = 0; j <= n; j++) {
    int64_t cur = 1; // money
    int64_t fab = 1;
    for (int i = 0; i < n; i++) {
      auto v = cur / a[i];
      if (i >= j) {
        v = 0;
      }
      fab += v;
      cur += fab - v * a[i];
    }
    ans = max(ans, cur - fab);
  }

  cout << ans;
}
