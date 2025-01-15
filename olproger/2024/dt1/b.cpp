// semenInRussia 2024
#include <cassert>
#include <cstdint>
#include <iostream>
#include <numeric>

using namespace std;

int main() {
  int64_t n, dk, tk, dm, tm;
  cin >> n >> dk >> tk >> dm >> tm;

  auto d = gcd(tk, tm);

  auto v1 = tm / d;
  auto v2 = tk / d;

  auto i1 = (dk + v1 - 1) / v1;
  auto i2 = (dm + v2 - 1) / v2;

  auto di = max(i1, i2);

  auto n1 = v1 * di;
  auto n2 = v2 * di;

  if (max(n1, n2) > n) {
    const int64_t inf = 1e18 + 1000;
    pair<int64_t, pair<int64_t, int64_t>> ans = {+inf, {0, 0}};

    auto i = max(dk, (n * tm + tk - 1) / tk);
    ans = min(ans, {i * tk, {i, n}});

    i = max(dm, (n * tk + tm - 1) / tm);
    ans = min(ans, {i * tm, {n, i}});

    auto [l, r] = ans.second;
    cout << min(l, n) << " " << min(r, n) << "\n";

    return 0;
  }

  cout << n1 << " " << n2 << "\n";
}
