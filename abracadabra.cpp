// https://codeforces.com/contest/2010/problem/C2
// semenInRussia 2024
#include <iostream>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")

const int N = 5e5;
int z[N];

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string s;
  cin >> s;
  int n = int(s.size());

  // build Z-prefix function
  int l = 0, r = 0;
  for (int i = 1; i < n; i++) {
    z[i] = 0;
    if (i >= l && i < r) {
      z[i] = min(z[i - l], r - i);
    }
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
      z[i]++;
    }
    if (z[i] + i > r) {
      r = z[i] + i;
      l = i;
    }
  }

  // find this prefix
  int ans = -1;
  for (int i = 1; i < n && ans == -1; i++) {
    // [0; z[i]] = [n-z[i]; n]
    if ((n - i) * 2 <= n) {
      continue;
    }
    if (z[i] == n - i && z[i] > n - z[i]) {
      ans = z[i];
    }
  }

  if (ans == -1) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
    for (int i = 0; i < ans; i++) {
      cout << s[i];
    }
  }
}
