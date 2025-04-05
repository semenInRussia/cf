// semenInRussia 2025
#include <algorithm>
#include <cstdint>
#include <iostream>

using namespace std;

void solve() {
  int l, r, d, u;
  cin >> l >> r >> d >> u;
  bool ok = max({l, r, d, u}) == min({l, r, d, u});
  cout << (ok ? "YES\n" : "NO\n");
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
