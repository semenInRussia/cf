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

void display_abc(P s, P t) {
  C a, b, c;
  if (s.X == t.X) {
    a = 1;
    b = 0;
    c = -s.X;
  } else {
    a = (t.Y - s.Y) / (s.X - t.X);
    b = 1;
    c = -a * s.X - s.Y;
  }
  cout << fixed << setprecision(8);
  cout << a << ' ' << b << ' ' << c;
}

int main() {
  freopen("bisector.in", "r", stdin);
  freopen("bisector.out", "w", stdout);
  //---

  P o, a, b;
  cin >> o >> a >> b;
  P oa = a - o;
  P ob = b - o;
  C s1 = abs(oa);
  C s2 = abs(ob);
  oa *= s2;
  ob *= s1;
  P ab = -oa + ob;
  P m = oa + (ab / 2.0);
  display_abc(o, o + m);
}
