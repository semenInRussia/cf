// semenInRussia 2025
#include <cstdint>
#include <iostream>

using namespace std;

// 0 - 0
// 1 - 4*x
// 2 - 1
// 3 - 4*x+3

// 000 : ...00
// ...01 : ...01
// ...10 : ...11
// 011 : ...00
// 100 : ..100
// 101 :
// 110 :
// 111 :

int64_t f(int64_t x) {
  if (x == -1) {
    return 0;
  }

  int64_t p[] = {0, x, 1, x + 1};

  // cout << x << ": " << p[x % 4] << "\n";

  return p[x % 4];
}

int main() {
  int64_t A, B;
  cin >> A >> B;
  cout << (f(B) ^ f(A - 1));
}
