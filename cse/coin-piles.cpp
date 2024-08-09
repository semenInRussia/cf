// semenInRussia 2024
// https://cses.fi/problemset/task/1754
#include <iostream>
using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int a, b;
    cin >> a >> b;

    bool ans = 1;
    if ((a + b) % 3)
      ans = 0;

    // x + 2y == a
    // x = a - 2y

    // (a - 2y) + y == s
    // a - y == s
    // y = a - s

    int s = (a + b) / 3;
    int y = a - s;
    int x = s - y;
    ans &= y >= 0 && x >= 0;
    ans &= ((x + 2 * y) == a) && ((y + 2 * x) == b);
    cout << (ans ? "YES\n" : "NO\n");
  }
}
