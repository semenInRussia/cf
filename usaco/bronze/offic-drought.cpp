// Copyright 2024 usaco

#include <bits/stdc++.h>
#define int long long
#define nl "\n"
using namespace std;

int exe() {
  int ans = 0, n;
  cin >> n;
  vector<int> h(n);
  for (int &x : h)
    cin >> x;

  if (n == 1)
    return 0;

  for (int j : {1, 2}) {
    for (int i = 1; i < n - 1; i++) {
      if (h[i] > h[i - 1]) {
        int dif = h[i] - h[i - 1];
        ans += 2 * dif, h[i + 1] -= dif, h[i] = h[i - 1];
      }
    }
    if (h[n - 1] > h[n - 2])
      return -1;
    // now h is non-increasing
    reverse(h.begin(), h.end());
    // now h is non-decreasing
  }
  // now h is all equal
  return h[0] < 0 ? -1 : ans;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(ios_base::failbit);
  int t;
  cin >> t;
  while (t--)
    cout << exe() << nl;
}
