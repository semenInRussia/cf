// semenInRussia 2025
#include <cstdint>
#include <iostream>

#include <map>
#include <vector>
using namespace std;

const int N = 25;
map<int64_t, int64_t> f[N][3];

void solve() {
  int64_t x, k;
  cin >> x >> k;

  string s = to_string(x);

  for (char &c : s) {
    c -= '0';
  }

  f[0][1][1] = 1;

  int n = (int)s.size();

  // 0 - small
  // 1 - equal
  // 2 - bigger

  for (int i = 0; i < n; i++) {
    for (int b : {0, 1, 2}) {
      for (auto [p, v] : f[i][b]) {
        for (int d = i == 0; d < 10; d++) {
          int t = (b == 0 || b == 2) ? b : (d == s[i] ? 1 : (d < s[i] ? 0 : 2));
          f[i + 1][t][p * d] += v;
        }
      }
    }
  }

  int64_t ans = 0;

  for (int i = 1; i <= n; i++) {
    vector<int> h = {0, 1};
    if (i < n) {
      h.push_back(2);
    }
    for (int b : h) {
      for (auto [p, v] : f[i][b]) {
        ans += v * int(p <= k);
      }
    }
  }

  cout << ans;
}

int main() {
  int tt = 1;

#ifdef home
  cin >> tt;
#endif

  while (tt--) {
    for (int i = 0; i < N; i++) {
      for (int b : {0, 1, 2}) {
        f[i][b].clear();
      }
    }

    solve();
    cout << "\n";
  }
}
