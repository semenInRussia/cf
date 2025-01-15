// semenInRussia 2025
#include <cstdint>
#include <iostream>

using namespace std;

const int mod = 1e9 + 7;

int pow(int a, int x) {
  int ans = 1;
  while (x) {
    if (x & 1) {
      ans *= a;
    }
    a *= a;
    x >>= 1;
  }
  return ans;
}

int main() {
  int a, v;
  cin >> a >> v;
  cout << pow(a, v);
}
