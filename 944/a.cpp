// Copyright 2024 semenInRussia

#include <iostream>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9 + 7;

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
