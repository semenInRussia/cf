// semenInRussia 2024
#include <cstdint>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,fma,bmi2,tune=native")

void solve() {
  string s;
  cin >> s;
  int n = int(s.size());

  for (auto &c : s) {
    c -= '0';
  }

  set<int> rest;
  for (int i = 0; i < n; i++) {
    rest.insert(i);
  }
  string ans;

  while (!rest.empty()) {
    int i = *rest.begin();
    rest.erase(rest.begin());
    pair<int, int> bst = {-1, -1}; // new digit, position

    int d = 0;
    for (int j : rest) {
      if (d >= 9) {
        continue;
      }
      d++;
      int p = s[j] - d;
      if (p > s[i]) {
        bst = max(bst, {p, -j});
      }
    }

    if (bst.first != -1) {
      int j = -bst.second;
      rest.erase(j);
      ans.push_back(bst.first);
      rest.insert(i);
    } else {
      ans.push_back(s[i]);
    }
  }

  for (auto &c : ans) {
    c += '0';
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
