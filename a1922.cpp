// Copyright 2024 @semenInRussia
// https://codeforces.com/contest/1922/problem/A
// math, peasy

#include <iostream>

using namespace std;

void solve() {
  size_t n;
  cin >> n;

  string a, b, c;
  cin >> a >> b >> c;

  for (size_t i = 0; i < n; i++) {
    if (a[i] == b[i] && b[i] != c[i] ||
        (a[i] != b[i] && a[i] != c[i] && b[i] != c[i])) {
      cout << "YES" << endl;
      return;
    }
  }

  cout << "NO" << endl;
}

int main() {
  int t;
  cin >> t;

  while (t--)
    solve();

  return 0;
}
