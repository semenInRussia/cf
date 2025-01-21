// semenInRussia 2025
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int64_t l, r, d;
  cin >> d >> l >> r;

  vector<int64_t> s;

  for (int i = 1; i * i <= d; i++) {
    if (d % i == 0) {
      s.push_back(i);
      s.push_back(d / i);
    }
  }

  sort(s.begin(), s.end());
  s.resize(unique(s.begin(), s.end()) - s.begin());

  int64_t ans = 0;

  for (auto a : s) {
    auto v = d / a;
    auto s2 = a - v;
    if (s2 % 2 == 1 || s2 < 0) {
      continue;
    }
    auto s = s2 / 2;
    if (l <= s * s && s * s <= r && (s + v) * (s + v) <= r) {
      ans++;
    }
  }

  cout << ans;
}
