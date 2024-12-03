// semenInRussia 2024
#include <cassert>
#include <iostream>
#include <numeric>
using namespace std;

int solve(int64_t a, int64_t b, int64_t &x, int64_t &y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return b;
  }
  int64_t x1, y1;
  auto d = solve(b % a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return d;
}

int main() {
  int64_t a, b, c;
  cin >> a >> b >> c;
  int64_t x, y;
  auto d = solve(a, b, x, y);
  assert(d > 0);

  if (c % d) {
    cout << "Impossible";
    return 0;
  }

  int64_t x1, y1;
  if (x > 0) {
    auto k = c * x / b;
    x1 = (c * x - b * k) / d;
    y1 = (c * y + a * k) / d;
  } else {
    auto k = (b - 1 - c * x) / b;
    x1 = (c * x + b * k) / d;
    y1 = (c * y - a * k) / d;
  }

  assert(x1 >= 0);

  cout << x1 << ' ' << y1;
}
