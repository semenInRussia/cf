// semenInRussia 2024
#include <iostream>
using namespace std;

const int mod = 1e9 + 7, N = 3.2e5, C = 600, K = 29;
int h[N], p[N];

int main() {
  p[0] = 1;
  for (int i = 0; i + 1 < N; i++)
    p[i + 1] = (1ll * p[i] * K) % mod;

  // ADD:
  //
  // small:
  // - check all sub-strings, update cnt
  // big:
  // - save
  //
  // CHECK:
  // small:
  // - check all substrings O(n)
  //  *
  // - check cnt O(1)
  // big: their count is about sqrt(N)
  // -
}
