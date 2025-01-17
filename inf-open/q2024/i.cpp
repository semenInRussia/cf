// semenInRussia 2025
#include <complex>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

using ld = long double;
using P = complex<ld>;

struct point {
  P pos;
  P d;
  int c;
};

istream &operator>>(istream &in, P &p) {
  ld x, y;
  in >> x >> y;
  p = {x, y};
  return in;
}

istream &operator>>(istream &in, point &p) { return in >> p.pos >> p.d >> p.c; }

void solve() {
  int n, t;
  cin >> n >> t;
  vector<point> p(n);

  for (auto &x : p) {
    cin >> x;
  }

  ld ans = -1;

  for (int k = 0; k <= t; k++) {
    ld cur = 0;

    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (p[i].c != p[j].c) {
          cur = max(cur, abs(p[i].pos - p[j].pos));
        }
      }
    }

    if (ans == -1 || cur < ans) {
      ans = cur;
    }

    for (auto &x : p) {
      x.pos += x.d;
    }
  }

  cout << setprecision(10) << fixed;
  cout << ans << "\n";
}

int main() {
  int tt = 1;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
