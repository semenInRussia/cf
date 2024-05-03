// Copyright 2024 semenInRussia

#include <iostream>
#include <map>
#include <numeric>
#include <vector>

using namespace std;
using ull = unsigned long long;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) {
    char ch;
    cin >> ch;
    x = ch - '0';
  }
  vector<int> b(n + 1);
  partial_sum(a.begin(), a.end(), b.begin() + 1);
  map<int, ull> cnt;
  cnt[0] = 1;
  ull ans = 0;
  for (int r = 1; r <= n; r++) {
    b[r] -= r;
    if (!cnt.count(b[r]))
      cnt[b[r]] = 0;
    ans += cnt[b[r]], cnt[b[r]]++;
  }
  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
}
