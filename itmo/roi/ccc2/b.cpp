// semenInRussia 2025
#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5;
int a[N];
int A;

string disp(int x) {
  string s;
  for (int j = 0; j < A; j++) {
    s += ((x >> j) & 1) + '0';
  }
  return s;
}

int T(int msk, int x) {
  for (int j = x; j >= 0; j--) {
    if ((msk >> j) & 1) {
      return msk ^ (1 << j) ^ (1 << x);
    }
  }
  return msk ^ (1 << x);
}

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    --a[i];
  }

  A = *max_element(a, a + n) + 1;

  vector<vector<int>> dp(n, vector<int>(1 << A));

  dp[0][1 << a[0]] = true;
  dp[1][1 << a[1]] = true;

  for (int i = 0; i < n; i++) {
    for (int b = 0; b < (1 << A); b++) {
      if (!dp[i][b]) {
        continue;
      }
      if (i + 1 < n) {
        dp[i + 1][T(b, a[i + 1])] = true;
      }
      if (i + 2 < n) {
        dp[i + 2][T(b, a[i + 2])] = true;
      }
    }
  }

  int ans = A;

  for (int i = n - 2; i < n; i++) {
    for (int b = 0; b < (1 << A); b++) {
      if (dp[i][b]) {
        ans = min(ans, __builtin_popcount(b));
      }
    }
  }
  cout << ans;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int tt = 1;
#ifdef home
  cin >> tt;
#endif
  while (tt--) {
    solve();
    cout << "\n";
  }
}
