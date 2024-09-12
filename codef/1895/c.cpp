// Copyright 2023 semenInRussia

#include <algorithm>
#include <cmath>
#include <iostream>
#include <optional>
#include <unordered_map>
#include <vector>

using namespace std;

using uint = unsigned int;

pair<uint, uint> num_lensum(size_t num) {
  uint len = 0;
  uint sum = 0;

  while (num) {
    sum += num % 10;
    num /= 10;
    len++;
  }

  return {sum, len};
}

using uint = unsigned int;

int main() {
  size_t n;
  cin >> n;

  vector<size_t> a(n);

  for (size_t i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<uint> t(n);
  unordered_map<uint, size_t> m;

  for (size_t i = 0; i < n; i++) {
    auto p = num_lensum(a[i]);

    uint sum = p.first;
    uint len = p.second;

    // t[i] = len and sum of a[i] in one number
    t[i] = len * 100 + sum;

    // add t[i] to m, count t[i]
    if (!m.count(t[i])) {
      m[t[i]] = 0;
    }

    m[t[i]]++;
  }

  size_t amnt = n;

  for (size_t i = 0; i < n; i++) {
    auto ti = t[i];

    uint len = ti / 100;
    uint sum = ti % 100;

    if (len <= 2) {
      continue;
    }

    uint max_mod = pow(10, len - 1);

    for (int exp_len = len - 2; exp_len >= 1; exp_len -= 2) {
      uint mod = pow(10, (len + exp_len) / 2 - exp_len);

      // a x at end
      uint l = num_lensum(a[i] / mod).first;
      uint r = num_lensum(a[i] % mod).first;

      if (r <= l) {
        uint exp_sum = l - r;
        uint exp = exp_len * 100 + exp_sum;

        if (m.count(exp)) {
          amnt += m[exp];
        }
      }

      // xx:2222
      uint mod2 = pow(10, (exp_len + len) / 2);

      l = num_lensum(a[i] / mod2).first;
      r = num_lensum(a[i] % mod2).first;

      if (l <= r) {
        uint exp_sum = r - l;
        uint exp = exp_len * 100 + exp_sum;

        if (m.count(exp)) {
          amnt += m[exp];
        }
      }

      mod /= 100;
    }
  }

  for (auto p : m) {
    size_t cnt = p.second;

    // if we have 2 numbers, with the same length and sum, then we
    // have two additional ways to create lucky ticket (i, j) and (j,
    // i), if we have cnt these numbers, we have cnt*(cnt-1) additionals ways
    if (cnt > 1) {
      amnt += cnt * (cnt - 1);
    }
  }

  cout << amnt << endl;
}
