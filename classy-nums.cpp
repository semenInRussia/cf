// semenInRussia 2024
// https://codeforces.com/contest/1036/problem/C?lang=en

#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;

const int N = 30, K = 3;
ll f[N][3][K + 1];

// f[i][S][k] - amount of integers with size=i, k amount of zeroes
//
// S is 0,1,2
// 0 - one digit is small than input number
// 1 - one is biggier
// 2 - is equal

ll solve(ll x) {
  if (x == 0) {
    return 0;
  }

  string num = to_string(x);
  for (auto &ch : num) {
    ch -= '0';
  }
  int n = int(num.size());

  f[0][2][0] = 1; // we have one EQUAL(S=2) integer
  for (int i = 1; i <= n; i++) {
    // clear:
    for (int s : {0, 1, 2}) {
      for (int k = 0; k <= K; k++) {
        f[i][s][k] = 0;
      }
    }

    for (int k = 0; k <= K; k++) {
      for (int d = i == 1; d < 10; d++) {
        int nk = k + (d != 0);
        if (nk > K)
          continue;
        f[i][0][nk] += f[i - 1][0][k];
        f[i][1][nk] += f[i - 1][1][k];
        if (d == num[i - 1]) {
          f[i][2][nk] += f[i - 1][2][k];
        } else {
          int ns = d > num[i - 1];
          f[i][ns][nk] += f[i - 1][2][k];
        }
      }
    }
  }

  ll ans = 1;
  for (int sz = 1; sz <= n; sz++) {
    for (int k = 0; k <= K; k++) {
      ans += f[sz][0][k];
      if (sz < n) {
        ans += f[sz][1][k];
        ans += f[sz][2][k];
      }
    }
  }

  return ans;
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    ll l, r;
    cin >> l >> r;
    cout << solve(r + 1) - solve(l) << '\n';
  }
}
