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
  freopen("line2.in", "r", stdin);
  freopen("line2.out", "w", stdout);
  //---

  P p, n;
  cin >> p >> n;

  C a = n.X;
  C b = n.Y;
  C c = -dot(n, p);

  cout << fixed << setprecision(8);
  cout << a << ' ' << b << ' ' << c;
}
