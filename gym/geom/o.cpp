// semenInRussia 2024
#include <cassert>
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
  freopen("line3.in", "r", stdin);
  freopen("line3.out", "w", stdout);
  //---

  long a, b, c, r;
  cin >> a >> b >> c >> r;

  cout << setprecision(8);
  if (b) {
    for (auto p : {-r, +r}) {
      cout << a << ' ' << b << ' ' << (c + p * b) << '\n';
    }
  } else {
    for (auto p : {-r, +r}) {
      cout << a << ' ' << b << ' ' << (c + p * a) << '\n';
    }
  }
}
