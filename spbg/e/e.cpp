// Copyright 2024 semenInRussia

#include <cmath>
#include <iostream>
#include <map>
#include <set>

using namespace std;

inline size_t trim(const size_t x, const size_t mod) noexcept {
  return x / mod + x % mod;
}

int main() {
  int n, x, y;
  cin >> n >> x >> y;

  int res = 1;
  const int mod = pow(10, n);
  map<int, int> seen, pow;

  for (int i = 1; i <= y; i++) {
    res *= x;

    while (res >= mod)
      res = trim(res, mod);

    if (seen.count(res)) {
      const int prev_i = seen[res];
      const int cycl = i - prev_i;
      res = pow[prev_i + (y - i) % cycl];
      // wtf???
      break;
    }

    seen[res] = i;
    pow[i] = res;
  }

  cout << res;
}
