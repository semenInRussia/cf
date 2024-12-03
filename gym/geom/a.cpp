// semenInRussia 2024
#define _USE_MATH_DEFINES

#include <cmath>
#include <complex>
#include <cstdio>
#include <iomanip>
#include <iostream>
using namespace std;

// #define M_PI (22.0 / 7.0)

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
  freopen("angle1.in", "r", stdin);
  freopen("angle1.out", "w", stdout);
  //---

  P p;
  cin >> p;
  cout << fixed << setprecision(8);
  C a = arg(p);
  if (a < 0) {
    a += M_PI * 2;
  }
  cout << a;
}
