// Copyright 2024 semenInRussia

#include <iostream>
#include <numeric>

using namespace std;

using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;
const int inf = 1e9;

void solve() {
  int x;
  cin >> x;

  pii ans = {-1, -1};
  for (int y = 1; y < x; y++)
    ans = max(ans, {gcd(x, y) + y, y});

  cout << ans.second << '\n';
}

int main() {
  int tt;
  cin >> tt;
  while (tt--)
    solve();
}
