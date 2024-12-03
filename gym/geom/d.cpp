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
  freopen("area1.in", "r", stdin);
  freopen("area1.out", "w", stdout);
  //---

  P a, b, c;
  cin >> a >> b >> c;
  cout << fixed << setprecision(8);
  cout << abs(cross(c - a, c - b) / 2);
}
