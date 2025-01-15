// semenInRussia 2025
#include <cstdint>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

const int mod = 1e9 + 7;

void solve(int64_t l, int64_t r, int64_t s) {

  auto n = r - l + 1;

  vector<int64_t> pref(n + 1);

  for (int i = 0; i < n; i++) {
    pref[i + 1] = pref[i] ^ (l + i);
  }

  // for (int i = 0; i <= n; i++) {
  //   cout << pref[i] << " ";
  // }
  // cout << "\n";

  map<int64_t, int> mp;

  int ans = 0;

  for (int i = 0; i <= n; i++) {
    (ans += mp[pref[i] ^ s]) %= mod;
    (mp[pref[i]] += 1) %= mod;
  }

  // pref[l] ^ pref[r] (l != r)

  // if (s == 0) {
  //   ans--;
  // }

  cout << ans << "\n";
}

int main() {
#ifdef home
  int n = 1000;
  vector<int64_t> pref(n + 1);
  int l = 1;

  for (int i = 0; i < n; i++) {
    pref[i + 1] = pref[i] ^ (l + i);
  }

  for (int i = 0; i < 10; i++) {
    for (int j = i + 1; j <= 10; j++) {
      if ((pref[i] ^ pref[j + 1]) == 0) {
        cout << i << " " << j << "\n";
      }
    }
  }
#else

  int64_t l, r, s;
  cin >> l >> r >> s;

  solve(l, r, s);

#endif
}
