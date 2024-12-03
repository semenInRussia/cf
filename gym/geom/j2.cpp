// semenInRussia 2024
#include <algorithm>
#include <complex>
#include <iomanip>
i
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
C orient(P p, P a, P b) { return cross(p - a, b - a); }

struct line {
  P v;
  C c;
  P p;

  line(P a, P b) : v(b - a), c(cross(b - a, a)), p(a) {}

  C side(P p) { return cross(v, p) - c; }
};

struct segm {
  P a, b;

  segm(P _a, P _b) : a(_a), b(_b) {}

  bool in_disk(P p) { return dot(a - p, b - p) <= 0; }
  bool include(P p) { return cross(b - a, p - a) == 0 && in_disk(p); }
};

struct ray {
  P a, b;

  ray(P _a, P _b) : a(_a), b(_b) {}
};

bool intersect(segm ab, segm cd) {
  P a = ab.a;
  P b = ab.b;
  P c = cd.a;
  P d = cd.b;
  C oa = orient(a, c, d);
  C ob = orient(b, c, d);
  C oc = orient(c, a, b);
  C od = orient(d, a, b);
  if (oa * ob < 0 && oc * od < 0) {
    return 1;
  }
  return ab.include(c) || ab.include(d) //
         || cd.include(a) || cd.include(b);
}

C dist(line ab, P p) {
  C s = ab.side(p);
  return abs(s) / abs(ab.v);
}

bool intersect(line ab, line cd) {
  if (cross(ab.v, cd.v) == 0) {
    P p = ab.p;
    assert(dist(ab, p) == 0.0);
    return dist(ab, p) == dist(cd, p);
  }
  return 1;
}

C dist(line ab, line cd) {
  if (intersect(ab, cd)) {
    return 0;
  }
  auto A1 = cd.v.Y;
  auto B1 = -cd.v.X;
  auto C1 = cd.c;

  auto v = ab.v;
  auto A2 = v.Y;
  auto B2 = -v.X;
  auto C2 = ab.c;

  if (B1) {
    return abs((C1 / B1) - (C2 / B2));
  }
  return abs((C1 / A1) - (C2 / A2));
}

bool intersect(line ab, segm cd) { return ab.side(cd.a) * ab.side(cd.b) <= 0; }

C dist(line ab, segm cd) {
  if (intersect(ab, cd)) {
    return 0;
  }
  return min(dist(ab, cd.a), dist(ab, cd.b));
}

bool intersect(line ab, ray s) {
  C d = dist(ab, s.a) + 2;
  segm f(s.a, s.a + d * (s.b - s.a));
  return intersect(ab, f);
}

C dist(line ab, ray s) {
  if (intersect(ab, s)) {
    return 0;
  }
  return dist(ab, s.a);
}

C dist(P a, P b) { return abs(a - b); }

C dist(segm ab, P p) { //
  P a = ab.a;
  P b = ab.b;
  if (dot(p - a, b - a) >= 0 && dot(p - b, a - b) >= 0) {
    line f(a, b);
    return dist(f, p);
  }
  return min(dist(a, p), dist(b, p));
}

C dist(segm ab, segm cd) {
  if (intersect(ab, cd)) {
    return 0;
  }
  return min(min(dist(ab, cd.a), dist(ab, cd.b)),
             min(dist(cd, ab.a), dist(cd, ab.b)));
}

bool intersect(segm ab, ray s) {
  C d = dist(ab, s.a) + 2;
  P v = s.b - s.a;
  segm f(s.a, s.a + v * d);
  return intersect(f, ab);
}

C dist(ray s, P p);

C dist(segm ab, ray s) {
  if (intersect(ab, s)) {
    return 0;
  }
  return min(dist(s, ab.a), min(dist(ab, s.a), dist(s, ab.b)));
}

C dist(ray s, P p) {
  if (dot(p - s.a, s.b - s.a) >= 0) {
    line f(s.a, s.b);
    return dist(f, p);
  }
  return dist(s.a, p);
}

C intersect(ray ab, ray cd) {
  C d = 100'000'000;
  segm f(ab.a, ab.a + d * (ab.b - ab.a));
  segm g(cd.a, cd.a + d * (cd.b - cd.a));
  return intersect(f, g);
}

C dist(ray ab, ray cd) {
  if (intersect(ab, cd)) {
    return 0;
  }
  return min(dist(cd, ab.a), dist(ab, cd.a));
}

int main() {
  freopen("distance5.in", "r", stdin);
  freopen("distance5.out", "w", stdout);

  P a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << fixed << setprecision(8);
  cout << dist(segm(a, b), segm(c, d));
}
