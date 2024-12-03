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

int main() {
  freopen("distance3.in", "r", stdin);
  freopen("distance3.out", "w", stdout);
  //---

  P p, a, b;
  cin >> p >> a >> b;

  C ans;

  if (dot(p - a, b - a) >= 0) {
    // distance to line
    C c = cross(b - a, a);
    C s = cross(b - a, p) - c;
    ans = abs(s) / abs(b - a);
  } else {
    ans = abs(p - a);
  }

  cout << fixed << setprecision(8);
  cout << ans;
}
