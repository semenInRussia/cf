// semenInRussia 2025
#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;

void solve(int n, int k, vector<int> a) {
  assert(k == 2);

  vector<int64_t> p(n + 1);

  p[0] = 0;
  for (int i = 0; i < n; i++) {
    p[i + 1] = p[i] + a[i];
  }

  int64_t ans = 0;

  for (int i = 1; i < n; i++) {
    auto s = p[i];
    auto t = p[n] - p[i];
    ans = max(ans, abs(t - s));
  }

  cout << ans;
}

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> a(n);

  for (int &x : a) {
    cin >> x;
  }

  if (k == 2) {
    solve(n, k, a);
    return 0;
  }

  int64_t ans = 0;

  for (int z : {1, 2}) {
    (void)z;

    vector<int64_t> p(n + 1), s(n);

    p[0] = 0;
    for (int i = 0; i < n; i++) {
      p[i + 1] = p[i] + a[i];
    }

    for (int i = n - 1; i >= 0; i--) {
      s[i] = a[i];
      if (i != n - 1) {
        s[i] = min(s[i], s[i + 1]);
      }
    }

    int m = n - k + 1;

    for (int i = 1; i < n; i++) {
      auto a1 = p[i] - p[max(i - m, 0)];
      auto a2 = s[i];
      ans = max(ans, a1 - a2);
    }

    reverse(a.begin(), a.end());
  }

  cout << ans;
}
