// Copyright 2024 semenInRussia

#include <iostream>

using namespace std;

void solve() {
  int x, y;
  cin >> x >> y;
  cout << min(x, y) << ' ' << max(x, y) << '\n';
}

int main() {
  int tt;
  cin >> tt;
  while (tt--)
    solve();
}
