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
  freopen("position.in", "r", stdin);
  freopen("position.out", "w", stdout);
  //---

  P p, q;
  cin >> p >> q;

  C a, b, c;
  cin >> a >> b >> c;

  C s1 = dot({a, b}, p) + c;
  C s2 = dot({a, b}, q) + c;

  cout << ((s1 * s2 < 0) ? "NO" : "YES");
}
