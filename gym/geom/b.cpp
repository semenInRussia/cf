// semenInRussia 2024
#define _USE_MATH_DEFINES

#include <cmath>
#include <complex>
#include <cstdio>
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
  freopen("angle2.in", "r", stdin);
  freopen("angle2.out", "w", stdout);
  //---

  P a, b;
  cin >> a >> b;
  cout << fixed << setprecision(8);
  cout << abs(atan2(cross(a, b), dot(a, b)));
}
