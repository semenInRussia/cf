// semenInRussia 2025
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int N = 1e5 + 100;

int64_t f[N][3][2];

int64_t func(string s) {
  for (auto &c : s) {
    c -= '0';
  }

  int n = (int)s.size();

  for (int i = 0; i <= n; i++) {
    for (int f1 : {0, 1, 2}) {
      for (int f2 : {0, 1}) {
        f[i][f1][f2] = 0;
      }
    }
  }

  f[0][1][0] = 1;

  for (int i = 0; i < n; i++) {
    for (int c : {1, 2, 3, 5, 7}) {
      for (int f1 : {0, 1, 2}) {
        for (int f2 : {0, 1}) {
          if (f2 && c != 1) {
            continue;
          }
          int t = -1;
          if (f1 == 0 || f1 == 2) {
            t = f1;
          } else {
            t = (c < s[i]) ? 0 : (c == s[i] ? 1 : 2);
          }
          f[i + 1][t][f2 || c != 1] += f[i][f1][f2];
        }
      }
    }
  }

  int64_t ans = 0;
  for (int len = 1; len <= n; len++) {
    int p = 1;
    ans += f[len][0][p];
    ans += f[len][1][p];
    if (len < n) {
      ans += f[len][2][p];
    }
  }

  // for (auto c : s) {
  //   cout << char(c + '0');
  // }
  // cout << "\n";
  // cout << ": " << ans << "\n";

  return ans;
}

bool check(string s) {
  for (auto &c : s) {
    c -= '0';
  }

  int bad = 0;

  for (int c : s) {
    if (c == 0 || c == 4 || c == 6 || c > 7) {
      return false;
    }
    bad += c != 1;
  }
  return bad == 1;
}

void solve() {
  // int ans = 0;
  // for (int x = 1; x <= 179; x++) {
  //   ans += check(to_string(x));
  // }
  // cout << "ans=" << ans << "\n";
  string a, b;
  cin >> a >> b;
  cout << func(b) - func(a) + check(a);
}

int main() {
  int tt = 1;
#ifdef home
  cin >> tt;
#endif
  while (tt--) {
    solve();
    cout << "\n";
  }
}
