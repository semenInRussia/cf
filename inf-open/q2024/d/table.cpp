// semenInRussia 2024
#include "table.h"
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")

const int N = 2e6 + 10;
vector<int> s[N];

int solve(int n, int t, vector<int> r, vector<int> c, vector<int> v) {
  for (int i = 0; i < t; i++) {
    int y = r[i] + c[i] - v[i];
    if (y >= 0) {
      s[y].push_back(v[i]);
    }
  }

  for (int i = 0; i < 2 * n; i++) {
    sort(s[i].begin(), s[i].end());
  }

  int ans = 0;

  for (int k = 1; k < 2 * n; k++) {
    int op = 0;
    for (int y = 0; y < 2 * n; y += k) { // count < k
      op += lower_bound(s[y].begin(), s[y].end(), k) - s[y].begin();
    }
    ans = max(op, ans);
  }

  return t - ans;
}
