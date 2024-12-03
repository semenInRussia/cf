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
  freopen("point1.in", "r", stdin);
  freopen("point1.out", "w", stdout);
  //---

  P p;
  C a, b, c;
  cin >> p >> a >> b >> c;

  bool ok = p.X * a + p.Y * b + c == 0;

  cout << (ok ? "YES" : "NO");
}
