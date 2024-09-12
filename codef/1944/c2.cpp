// Copyright 2024 ElizaBest

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;
using ll = long long;
using ld = long double;

const ll N = 2e5 + 10;
const ll mod = 998244353;
const ll INF = 2e9;

void solve() {
  int n;
  cin >> n;
  vector<int> cnt(n);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    cnt[a]++;
  }
  int mex = n;
  int cnt_alone = 0;
  for (int i = 0; i < n; i++) {
    if (cnt[i] == 0) {
      mex = i;
      break;
    }
    if (cnt[i] == 1) {
      cnt_alone++;
      if (cnt_alone == 2) {
        mex = i;
        break;
      }
    }
  }
  cout << mex << '\n';
}

signed main() {
  ll t;
  cin >> t;
  while (t--)
    solve();
}
