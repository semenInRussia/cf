// semenInRussia 2025
#include <cstdint>
#include <iostream>

using namespace std;

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int x, y;
    cin >> x >> y;

    // we can -= 9x + 1
    int d = x - y;

    // x + 1 - y = 9=

    bool ans = (d > 0 && (d + 1) % 9 == 0) || x + 1 == y;

    cout << (ans ? "YES\n" : "NO\n");
  }
}
