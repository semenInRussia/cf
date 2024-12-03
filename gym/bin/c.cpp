// semenInRussia 2024
#include <algorithm>
#include <cassert>
#include <complex>
#include <iomanip>
#include <iostream>
using namespace std;

using C = long double;
using P = complex<C>;

istream &operator>>(istream &in, P &v) {
  C x, y;
  in >> x >> y;
  v = {x, y};
  return in;
}

#define X real()
#define Y imag()

C dot(P a, P b) { return (conj(a) * b).X; }
C cross(P a, P b) { return (conj(a) * b).Y; }

int main() {
  P s = ;

  P v = {1, k};
  C c = cross(v, {0, b});

  auto f = [k, b, s, t](C x) {
    P p = {x, k * x + b};
    return abs(p - s) + abs(p - t);
  };

  C l = min(s.X, t.X);
  C r = max(s.X, t.X);

  C ans = min(f(l), f(r));

  const C eps = 1e-6;

  while (r - l > eps) {
    C a = l + (r - l) / 3.0;
    C b = r - (r - l) / 3.0;
    if (f(a) < f(b)) {
      r = b;
    } else {
      l = a;
    }
  }

  ans = min(ans, f((r + l) / 2.0));

  cout << fixed << setprecision(3);
  cout << ans;
}
