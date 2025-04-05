// semenInRussia 2025
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

const int N = 3e5;
int a[N], b[N];

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int tt;
  cin >> tt;

  mi i2 = inv(2);

  while (tt--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
      b[i + 1] = (a[i] == 2) + b[i];
    }

    mi s = 0;
    mi ans = 0;
    int cnt1 = 0;

    for (int i = 0; i < n; i++) {
      if (a[i] == 1) {
        cnt1++;
        s += pow(i2, b[i]);
      }
      if (a[i] == 3) {
        ans += pow(2, b[i + 1]) * s - cnt1;
      }
    }

    cout << ans << "\n";
  }
}
