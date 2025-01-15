// semenInRussia 2024
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int64_t f(int64_t x) {
  int64_t ans = (x / 9) * 45;
  for (int i = 1; i <= (x % 9); i++) {
    ans += i;
  }
  return ans;
}

int main() {
  int q;
  cin >> q;
  while (q--) {
    int64_t l, r;
    cin >> l >> r;
    cout << f(r) - f(l - 1) << "\n";
  }
}
