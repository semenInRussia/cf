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
  C c;
  P v;

  line(C a, C b, C _c) : v(b, -a), c(_c) {}
  // line(P a, P b) : v(b - a), c(cross(v, a)) {}
  line() {}

  C side(P p) { return cross(v, p) - c; }
  C dist(P p) { return abs(side(p)) / abs(v); }
};

int main() {
  freopen("distance1.in", "r", stdin);
  freopen("distance1.out", "w", stdout);
  //---

  P p;
  C a, b, c;
  cin >> p;
  cin >> a >> b >> c;
  line f(a, b, -c);
  cout << fixed << setprecision(8);
  cout << f.dist(p);
}
