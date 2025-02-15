// semenInRussia 2025
#include <cassert>
#include <cstdint>
#include <iomanip>
#include <iostream>

using namespace std;
using T = long double;

const T Eps = 0.01;

const int N = 21;
string t[N];

T sqr(T x) { return x * x; }

int n;

bool check(T x, T y, T rad) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      T xp = T(i) + 0.5;
      T yp = T(j) + 0.5;
      bool ins = sqr(xp - x) + sqr(y - yp) < sqr(rad);
      if (!ins && t[i][j] == '#') {
        return false;
      }
    }
  }
  return true;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }

  T dx = 0.05;

  for (T x = 0; x < n; x += dx) {
    for (T y = 0; y < n; y += dx) {
      T l = 0;
      T r = 21;
      while (r - l > Eps) {
        auto m = (r + l) * 0.5;
        bool ok = check(x, y, m);
        if (ok) {
          r = m;
        } else {
          l = m;
        }
      }

      int bad = 0;

      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          T xp = T(i) + 0.5;
          T yp = T(j) + 0.5;
          bool ins = sqr(xp - x) + sqr(y - yp) < sqr(r);
          if (ins && t[i][j] == '.') {
            bad++;
          }
        }
      }

      if (check(x, y, r) && bad == 0) {
        cout << setprecision(6) << fixed;
        cout << y << " " << x << " " << r;
        return 0;
      }
    }
  }

  assert(0 && "unreachable!");
}
