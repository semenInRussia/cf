// semenInRussia 2025
#include <algorithm>
#include <complex>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

using T = long double;
using P = complex<T>;

#define X real()
#define Y imag()

T dot(P a, P b) { return (conj(a) * b).X; }
T cross(P a, P b) { return (conj(a) * b).Y; }
T sq(P a) { return a.X * a.X + a.Y * a.Y; }

istream &operator>>(istream &in, P &v) {
  T x, y;
  in >> x >> y;
  v = {x, y};
  return in;
}

const int N = 25;
P a[N], h[N];

T per(P a[N], int n) {
  T p = 0;
  for (int i = 0; i < n; i++) {
    p += abs(a[i] - a[(i + 1) % n]);
  }
  return p;
}

T area(P a[N], int n) {
  T s = 0;
  for (int i = 0; i < n; i++) {
    s += cross(a[i], a[(i + 1) % n]);
  }
  return abs(s);
}

int main() {
#ifndef home
  freopen("reduce.in", "r", stdin);
  freopen("reduce.out", "w", stdout);
#endif
  // cin.tie(nullptr)->sync_with_stdio(0);
  int n;
  cin >> n;
  T lim;
  cin >> lim;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  // for (int i = 1; i < n; i++) {
  //   if (a[i].X < a[0].X || (a[i].X == a[0].X && a[i].Y < a[0].Y)) {
  //     swap(a[0], a[i]);
  //   }
  // }

  T ans = 0;

  for (int b = 0; b < (1 << n); b++) {
    int k = 0;
    for (int i = 0; i < n; i++) {
      if ((b >> i) & 1) {
        h[k++] = a[i];
      }
    }

    if (per(h, k) <= lim) {
      ans = max(ans, abs(area(h, k)));
    }
  }

  cout << setprecision(8) << fixed;
  cout << ans / 2;
}
