// semenInRussia 2024
#include <cstdint>
#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    int x = (1000 - n) / 7;
    if (1000 - 7 * x == n && x > 0) {
      cout << x << "\n";
    } else {
      cout << "-1\n";
    }
  }
}
