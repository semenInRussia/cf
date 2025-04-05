// semenInRussia 2025
#pragma GCC optimize("O3,unroll-loops")

#include <cstdint>
#include <iostream>

#pragma GCC target("avx2")

using namespace std;

const int64_t S = 1e7 + 5;

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int64_t n;
  cin >> n;

  int64_t ans = 0;

  for (int j = 1; j < S; j++) {
    ans += n / j;
    if (j > n) {
      break;
    }
  }

  for (int v = 1; v < S; v++) {
    int64_t l = max(S, n / (v + 1) + 1);
    int64_t r = n / v;
    auto len = max(r - l + 1, 0ll);
    ans += len * v;
  }

  cout << ans;
}
