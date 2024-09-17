// semenInRussia 2024
using namespace std;
#include <algorithm>
#include <iostream>
using ll = long long;

bool have9(ll x) {
  while (x) {
    if (x % 10 == 9) {
      return 1;
    }
    x /= 10;
  }
  return 0;
}

ll f[20][2][2];
ll solve(ll x) {
  // f[i][small][big]
  string s = to_string(x);
  for (auto &ch : s) {
    ch = ch - '0';
  }
  int n = int(s.size());
  for (int i = 0; i <= n; i++) {
    f[i][0][0] = f[i][0][1] = f[i][1][0] = 0;
  }
  f[0][0][0] = 1;
  for (int i = 1; i <= n; i++) {
    int c = s[i - 1];
    f[i][0][0] = count(s.begin(), s.begin() + i, 9) == 0;
    for (int d = i == 1; d < 10; d++) {
      if (d == 9) {
        continue;
      }

      // s=0,b=1
      f[i][0][1] += f[i - 1][0][1];
      if (d > c) {
        f[i][0][1] += f[i - 1][0][0];
      }

      // s=1, b=0
      f[i][1][0] += f[i - 1][1][0];
      if (d < c) {
        f[i][1][0] += f[i - 1][0][0];
      }
    }
    // cout << i << "(small) = " << f[i][1][0] << '\n';
    // cout << i << "(big) = " << f[i][0][1] << '\n';
    // cout << i << "(bad) = " << f[i][0][0] << '\n';
  }

  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += f[i][1][0] + f[i][0][0];
    if (i != n) {
      ans += f[i][0][1];
    }
  }

  // cout << "=" << ans << '\n';
  return ans;
}

int main() {
  ll l, r;
  cin >> l >> r;
  cout << solve(r) - solve(l) + !have9(l);
}
