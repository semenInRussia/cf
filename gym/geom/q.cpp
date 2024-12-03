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
  freopen("point2.in", "r", stdin);
  freopen("point2.out", "w", stdout);
  //---

  P p, a, b;
  cin >> p >> a >> b;

  bool ok = cross(p - a, b - a) == 0 && dot(p - a, b - a) >= 0;
  ok |= p == a;
  cout << (ok ? "YES" : "NO");
}
