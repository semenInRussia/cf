// semenInRussia 2024
#include <cstdint>
#include <iostream>

using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  cout << max(n, m) + 1 << "\n";
}

int main() {
  int tt = 1;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
