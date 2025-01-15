// semenInRussia 2025
#include <cstdint>
#include <iostream>
#include <map>

using namespace std;

const int mod = 1e9 + 7;

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

const int N = 2e5 + 1000;
mi fac[N];
mi v[N];

mi C(int n, int k) { return fac[n] / (fac[k] * fac[n - k]); }

int main() {
  int n;
  cin >> n;

  fac[0] = 1;
  for (int i = 1; i < N; i++) {
    fac[i] = fac[i - 1] * i;
  }

  map<int, int> cnt;

  int K = 0;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    cnt[x]++;
    K = max(K, cnt[x]);
  }

  for (int i = 0; i <= K; i++) {
    v[i] = 1;
  }

  for (auto [_, c] : cnt) {
    for (int i = 1; i <= c; i++) {
      v[i] *= (C(c, i) + 1);
    }
  }

  mi ans = 0;
  for (int i = 0; i <= K; i++) {
    ans += v[i];
  }

  cout << ans - K;
}
