// semenInRussia 2024
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
  freopen("line1.in", "r", stdin);
  freopen("line1.out", "w", stdout);
  //---

  P s, t;
  cin >> s >> t;

  P st = t - s;

  C a = -st.Y;
  C b = st.X;
  C c = -dot({a, b}, s);

  cout << fixed << setprecision(8);
  cout << a << ' ' << b << ' ' << c;
}
