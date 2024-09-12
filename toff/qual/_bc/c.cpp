// semenInRussia 2024
#include <algorithm>
#include <iostream>
using namespace std;
using ull = unsigned long long;

const int N = 2e5;
int a[N];

int main() {
  int m, n;
  cin >> m >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  reverse(a, a + n);
  int l = 0, r = 0; // bound of the group with the same value
  while (m) {
    while (r + 1 < n && a[l] == a[r + 1]) {
      r++;
    }
    int nxt = a[r + 1];
    if (r + 1 == n) {
      nxt = 0;
    }

    // decrease all them
    int k = min(a[l] - nxt, m / (r - l + 1));
    for (int i = l; i <= r; i++) {
      a[i] -= k;
      m -= k;
    }
    for (int i = l; i <= r; i++) {
      if (m && a[i] > nxt) {
        m--;
        a[i]--;
      }
    }
  }

  ull ans = 0;
  for (int i = 0; i < n; i++) {
    ans += size_t(a[i]) * a[i];
  }
  cout << ans;
}
