// semenInRussia 2024
#include <iostream>
using namespace std;

const int mod = 1e9 + 7;
struct mi {
  int v;
  mi(int64_t x = 0) : v(x % mod) { v += mod * (v < 0); }
};

mi operator+(mi a, mi b) { return mi(1ll * a.v + 1ll * b.v); }
mi operator-(mi a) { return mi(-a.v); }
mi operator-(mi a, mi b) { return a + (-b); }
mi operator*(mi a, mi b) { return mi(1ll * a.v * b.v); }

mi &operator*=(mi &a, mi b) { return a = a * b; }
mi &operator+=(mi &a, mi b) { return a = a + b; }

mi pow(mi x, int64_t k) {
  mi ans = 1;
  while (k) {
    if (k & 1) {
      ans *= x;
    }
    k >>= 1;
    x *= x;
  }
  return ans;
}

mi inv(mi x) { return pow(x, mod - 2); }
mi operator/(mi a, mi b) { return a * inv(b); }

istream &operator>>(istream &in, mi &v) { return in >> v.v; }
ostream &operator<<(ostream &out, mi v) { return out << v.v; }

int main() {
  int n;
  cin >> n;

  int p, k;
  cin >> p >> k;

  k--;

  mi ans;

  if (p == 0) {
    mi b1 = pow(2, 1ll * k * n);
    mi q = 2;
    ans = b1 * (pow(q, n) - 1) / (q - 1);
  } else if (p == 1) {
    mi b1 = pow(2, k);
    mi q = pow(2, n);
    ans = b1 * ((pow(q, n) - 1) / (q - 1));
  } else {
    if (k == 0) {
      mi q = pow(2, n + 1);
      mi b1 = 1;
      ans = b1 * ((pow(q, n) - 1) / (q - 1));
    } else {
      mi q = pow(2, n - 1);
      mi b1 = pow(2, n - 1);
      ans = b1 * ((pow(q, n) - 1) / (q - 1));
    }
  }

  cout << ans;
}
