// Copyright 2024 semenInRussia

#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
using ull = unsigned long long;
const int inf = 1e9;

void solve() {
  string s;
  cin >> s;
  int ans = 0, n = (int)s.size();

  int o = 0, z = 0;
  for (int i = 0; i < n; i++) {
    z = 0;
    // find ones, find zeroes after
    // ans += (o + 1) * z
    int j = i;
    while (j < n && s[j] == '1')
      j++, o++;
    while (j < n && s[j] == '0')
      j++, z++;
    ans += o == 0 ? 0 : (o + 1) * z;
    i = j;
  }

  cout << ans << '\n';
}

int main() {
  int tt;
  cin >> tt;
  while (tt--)
    solve();
}
