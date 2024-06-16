// semenInRussia 2024
// https://codeforces.com/problemset/problem/1950/E
#include <iostream>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int ans = n;
  for (int x = n - 1; x > 0; x--) {
    if (n % x)
      continue;
    int difs = n, cur;
    for (int o : {0, x}) {
      cur = 0;
      for (int i = 0; i < n; i++)
        if (s[i] != s[i % x + o])
          cur++;
      difs = min(difs, cur);
    }
    if (difs <= 1)
      ans = x;
  }
  cout << ans << '\n';
}

int main() {
  int tt;
  cin >> tt;
  while (tt--)
    solve();
}
