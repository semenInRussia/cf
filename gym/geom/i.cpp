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
  line(P a, P b) : v(b - a), c(cross(b - a, a)) {}
  line() {}

  C side(P p) { return cross(v, p) - c; }
  C dist(P p) { return abs(side(p)) / abs(v); }
};

struct segm {
  P a, b;
  segm(P _a, P _b) : a(_a), b(_b) {}
  segm() {}

  C dist(P p) {
    if (dot(p - a, b - a) >= 0 && dot(p - b, a - b) >= 0) {
      line ab(a, b);
      return ab.dist(p);
    }
    return min(abs(p - a), abs(p - b));
  }
};

int main() {
  freopen("distance4.in", "r", stdin);
  freopen("distance4.out", "w", stdout);
  //---

  P p, a, b;
  cin >> p >> a >> b;

  segm ab(a, b);

  cout << fixed << setprecision(8);
  cout << ab.dist(p);
}
