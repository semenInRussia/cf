// semenInRussia 2024
#include <cstdint>
#include <iostream>

using namespace std;

using ull = unsigned long long;

// 10^18
// 2^30

int main() {

  // k * (2^x) >= 10**n
  // h * (2^x) > 10**(n + 1)

  ull n, x;
  cin >> n >> x;

  ull p10 = 1;
  for (int i = 0; i < n; i++) {
    p10 *= 10;
  }

  ull p2 = 1ull << x;

  ull k = ((p10 / 10) + p2 - 1) / p2;
  ull h = (p10 / p2) + 1;

  cout << h - k - 1;
}
