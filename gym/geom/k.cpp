// semenInRussia 2024
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <iomanip>
#include <iostream>
using namespace std;

using C = double;
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
  freopen("intersec1.in", "r", stdin);
  freopen("intersec1.out", "w", stdout);
  //---

  C a1, b1, c1;
  C a2, b2, c2;
  cin >> a1 >> b1 >> c1;
  cin >> a2 >> b2 >> c2;

  // a1 * x + b1 * y + c = 0
  // a2 * x + b2 * y + c = 0

  // (a1 - a2)x + c1 - c2 = 0
  // x = (c2 - c1)/(a1 - a2)

  C s1 = b1;
  C s2 = b2;

  C x, y;

  if (s1 == 0 || s2 == 0) {
    if (s1 == 0) {
      swap(a1, a2);
      swap(b1, b2);
      swap(c1, c2);
    }
    // Ax + By + C = 0
    // Ax + C = 0
    // x = -C / A
    x = -c2 / a2;
    y = (-c1 - a1 * x) / b1;
  } else {
    a1 *= s2, b1 *= s2, c1 *= s2;
    a2 *= s1, b2 *= s1, c2 *= s1;

    x = (c2 - c1) / (a1 - a2);
    y = (-c1 - a1 * x) / b1;
  }

  cout << fixed << setprecision(8);
  cout << x << ' ' << y;
}
