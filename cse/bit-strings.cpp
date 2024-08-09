// semenInRussia 2024
// https://cses.fi/problemset/task/1617
#include <iostream>
using namespace std;
const int mod = 1e9 + 7;

int main() {
  int n;
  cin >> n;
  int ans = 1;
  int b = 2;
  while (n) {
    if (n & 1)
      ans = 1ll * b * ans % mod;
    n >>= 1;
    b = 1ll * b * b % mod;
  }
  cout << ans;
}
