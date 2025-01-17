

#include "table.h"
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

using sieve = vector<vector<int>>;

vector<int> divs(int st, int x) {
  vector<int> ans = {};
  for (int i = 1; i * i <= x; i++) {
    if (x % i == 0) {
      ans.push_back(i);
      ans.push_back(x / i);
    }
  }

  sort(ans.begin(), ans.end());
  ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
  reverse(ans.begin(), ans.end());
  while (ans.size() && ans.back() < st) {
    ans.pop_back();
  }
  return ans;
}

int solve(int n, int t, vector<int> r, vector<int> c, vector<int> v) {
  vector<int> good(2 * n), add(2 * n + 1);

  // for all y, find divisors of y > v[j]

  // for divisors;
  // find multipliers

  for (int j = 0; j < t; j++) {
    int x = r[j] + c[j];

    if (x - v[j] == 0) {
      add[v[j]]++;
      continue;
    }
    if (x - v[j] > 0) {
      // find divisors (d) of y, that d > v[j], d < 2n
      int y = x - v[j];
      for (int d : divs(v[j] + 1, y)) {
        good[d]++;
      }
    }
  }

  int ans = t;
  int pref = 0;
  for (int i = 0; i < 2 * n; i++) {
    ans = min(ans, t - good[i] - pref);
    pref += add[i];
  }

  return ans;
}
