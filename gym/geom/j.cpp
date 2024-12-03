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

struct segm {
  P a, b;

  segm(P _a, P _b) : a(_a), b(_b) {}
  segm() {}

  C dist(segm s) {
    if (inter(s)) {
      return 0;
    }
    P c = s.a;
    P d = s.b;
    return min(min(dist(c), dist(d)), min(s.dist(a), s.dist(b)));
  }

  C dist(P p) {
    C h = 0;
    // perpendicular on segment
    if (dot(p - a, b - a) >= 0 && dot(p - b, a - b) >= 0) {
      // distance to AB
      P ab = b - a;
      C c = cross(ab, a);
      C s = cross(ab, p) - c;
      h = abs(s) / abs(ab);
    } else {
      h = min(abs(p - a), abs(p - b));
    }
    return h;
  }

  bool in_disk(P p) { return dot(b - p, a - p) <= 0; }
  bool include(P p) { return cross(b - a, p - a) == 0 && in_disk(p); }

  bool inter(segm cd) {
    P c = cd.a;
    P d = cd.b;
    C oc = cross(b - a, c - a);
    C od = cross(b - a, d - a);
    C oa = cross(d - c, a - c);
    C ob = cross(d - c, b - c);
    if (oc * od < 0 && oa * ob < 0) {
      return 1;
    }
    for (auto p : {c, d}) {
      if (include(p)) {
        return 1;
      }
    }
    for (auto p : {a, b}) {
      if (cd.include(p)) {
        return 1;
      }
    }
    return 0;
  }
};

int main() {
  freopen("distance5.in", "r", stdin);
  freopen("distance5.out", "w", stdout);
  //---

  P a, b, c, d;
  cin >> a >> b >> c >> d;

  segm ab(a, b), cd(c, d);

  cout << fixed << setprecision(8);
  cout << ab.dist(cd);
}
