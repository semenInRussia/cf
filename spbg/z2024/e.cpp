// semenInRussia 2025
#include <cassert>
#include <cstdint>
#include <iostream>

using namespace std;

const int mod = 998244353;

struct mi {
  int v;
  mi(int64_t x = 0) : v(x % mod) { v += mod * (x < 0); }
  explicit operator int() { return v; }
};

mi operator*(mi a, mi b) { return mi(1ll * a.v * b.v); }
mi &operator*=(mi &a, mi b) { return a = a * b; }

mi operator+(mi a, mi b) { return mi(1ll * a.v + b.v); }
mi &operator+=(mi &a, mi b) { return a = a + b; }

mi operator-(mi a, mi b) { return mi(a.v - b.v); }
mi &operator-=(mi &a, mi b) { return a = a - b; }

ostream &operator<<(ostream &out, mi v) { return out << v.v; }

const int N = 1005;
const int B = 1 << 2;
mi f[N][B];

int main() {
  int w, h;
  cin >> w >> h;
  f[0][0] = 1;
  assert(w == 2);

  for (int i = 1; i <= h; i++) {
    f[i][0] = f[i - 1][0];
    if (i >= 2) {
      f[i][0] += f[i - 2][0];
    }
    f[i][0] += f[i - 1][0b10];
    f[i][0] += f[i - 1][0b01];

    // 01
    f[i][0b01] = f[i - 1][0b10];
    if (i >= 2) {
      f[i][0b01] += f[i - 2][0];
    }

    // 10
    f[i][0b10] = f[i - 1][0b01];
    if (i >= 2) {
      f[i][0b10] += f[i - 2][0];
    }
  }

  cout << f[h][0b00];
}
