// semenInRussia 2025
#pragma GCC optimize("Ofast,unroll-loops")
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>
#pragma GCC target("avx2")

using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n;
  cin >> n;

  string s;
  cin >> s;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    a[i] = (s[i] == '(' ? +1 : -1);
  }

  vector<int> pref(n + 1);
  for (int i = 0; i < n; i++) {
    pref[i + 1] = pref[i] + a[i];
  }

  int ans = 0;

  for (int l = 0; l < n; l++) {
    int mx = pref[l];
    for (int r = l + 1; r <= n; r++) {
      bool ok = true;
      mx = max(pref[r - 1], mx);
      for (int i = l; i < r; i++) {
        if (pref[r] - mx + pref[l] < 0) {
          ok = false;
          break;
        }
      }
      ans += ok;
    }
  }

  cout << ans;
}
