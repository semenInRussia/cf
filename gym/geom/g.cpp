// semenInRussia 2024
#include <complex>
#include <cstdio>
#include <iomanip>
#include <iostream>
using namespace std;

using C = double;
using P = complex<C>;

#define X real()
#define Y imag()

istream &operator>>(istream &in, P &v) {
  C x, y;
  in >> x >> y;
  v = {x, y};
  return in;
}

C dot(P a, P b) { return (conj(a) * b).X; }
C cross(P a, P b) { return (conj(a) * b).Y; }

struct line {
  P v;
  C c;

  line(C a, C b, C _c) : v(b, -a), c(_c) {}
  line(P a, P b) : v(b - a), c(cross(v, a)) {}
  line() {}

  C side(P p) { return cross(v, p) - c; }
  C dist(P p) { return abs(side(p)) / abs(v); }
};

int main() {
  freopen("distance2.in", "r", stdin);
  freopen("distance2.out", "w", stdout);
  //---

  P p;
  P a, b;
  cin >> p >> a >> b;
  line f(a, b);
  cout << fixed << setprecision(8);
  cout << f.dist(p);
}
