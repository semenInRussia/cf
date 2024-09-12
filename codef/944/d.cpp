// Copyright 2024 semenInRussia

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9 + 7;

void solve() {
  string s;
  cin >> s;
  if (is_sorted(s.begin(), s.end())) {
    cout << "1\n";
    return;
  }

  int n = (int)s.size();
  vector<int> prts;
  for (int i = 1; i < n; i++)
    if (s[i] != s[i - 1])
      prts.push_back(s[i - 1] - '0');
  prts.push_back(s[n - 1] - '0');

  int m = (int)prts.size();
  int ans = 1;
  for (int i = 0; i < m; i++)
    if (prts[i] == 1 && i != m - 1)
      ans++;

  reverse(prts.begin(), prts.end());
  if (prts.back() == 0) {
    prts.pop_back();
    if (!prts.empty())
      prts.pop_back();
    ans = 1 + (int)prts.size();
  } else {
    prts.pop_back(), ans = 1; // pop 1
    if (!prts.empty()) {      // pop 0
      prts.pop_back();
      ans = 2;
      if (!prts.empty()) { // pop 1
        prts.pop_back();
        ans = 2 + (int)prts.size();
      }
    }
  }

  cout << ans << '\n';
}

int main() {
  int tt;
  cin >> tt;
  while (tt--)
    solve();
}
