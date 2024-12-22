// semenInRussia 2024
#include <cstdint>
#include <iostream>
using namespace std;

void solve() {
  int n;
  cin >> n;

  // a + b = n

  int ans = 0;
  for (int b = 1; b <= n; b++) {
    int a = n - b;
    ans += a > 0;
  }
  cout << (ans) << "\n";
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
