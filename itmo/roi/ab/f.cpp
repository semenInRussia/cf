// semenInRussia 2025
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

const int N = 3e5;

int64_t dp[2][2];
int lef[2][2], rig[2][2];

int a[N], b[N], c[N];

int64_t pref[N];

int main() {
  int n;
  cin >> n;

  int64_t sum = 0;

  for (int i = 0; i < n; i++) {
    cin >> c[i] >> a[i] >> b[i];
    sum += c[i];
  }

  set<pair<int, int>> suf;

  for (int i = 0; i < n; i++) {
    suf.insert({-c[i] + b[i], i});
  }

  pair<int64_t, pair<int, int>> ans = {0, {-1, -1}};
  pair<int, int> pref = {-c[0] + b[0], 0};

  for (int i = 0; i < n; i++) {
    pair<int, int> cur = {-c[i] + b[i], i};
    suf.erase(cur);

    if (i != 0) {
      auto [p, j] = pref;
      ans = max(ans, {sum - c[i] + a[i] + p, {i, j}});
    }

    if (i != n - 1) {
      auto [p, j] = *suf.rbegin();
      ans = max(ans, {sum - c[i] + a[i] + p, {i, j}});
    }

    pref = max(pref, cur);
  }

  cout << ans.first << "\n";
  auto [i, j] = ans.second;
  cout << (i + 1) << " " << (j + 1);
}
