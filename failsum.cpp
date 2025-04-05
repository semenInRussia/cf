// semenInRussia 2025
// https://leetcode.com/problems/minimum-falling-path-sum-ii/
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
const ll inf = 1e18 + 100;

class Solution {
public:
  int minFallingPathSum(vector<vector<int>> &a) {
    int n = (int)a.size();
    int m = (int)a[0].size();
    vector<vector<ll>> dp(n + 1, vector<ll>(m, +inf));
    vector<ll> suf(m, 0);

    for (int j = 0; j < m; j++) {
      dp[0][j] = 0;
    }

    for (int i = 0; i < n; i++) {
      ll pref = +inf;
      for (int j = 0; j < m; j++) {
        dp[i + 1][j] = min(suf[j], pref) + a[i][j];
        pref = min(pref, dp[i][j]);
      }

      fill(suf.begin(), suf.end(), +inf);
      for (int j = m - 1; j >= 1; j--) {
        suf[j - 1] = min(suf[j], dp[i + 1][j]);
      }
    }

    return *min_element(dp[n].begin(), dp[n].end());
  }
};
