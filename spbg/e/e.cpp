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
  size_t n, x, y;
  cin >> n >> x >> y;

  size_t res = 1;
  const size_t mod = pow(10, n);

  // a[i] = x^i
  // a[x^i] = i
  map<size_t, size_t> seen;
  map<size_t, size_t> pow;

  for (size_t i = 1; i <= y; i++) {
    res *= x;

    while (res >= mod)
      res = trim(res, mod);

    if (seen.count(res)) {
      const size_t prev_i = seen[res];
      const size_t cycl = i - prev_i;
      res = pow[prev_i + (y - i) % cycl];
      // wtf???
      break;
    }

    seen[res] = i;
    pow[i] = res;
  }

  cout << res << endl;
}
