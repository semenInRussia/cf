// semenInRussia 2025
#include <cmath>
#include <cstdint>
#include <iostream>

using namespace std;

const int mod = 1e9 + 7;

int main() {
  long long a, x;
  cin >> a >> x;
  long long v = pow(a, x);
  cout << v % mod;
}
