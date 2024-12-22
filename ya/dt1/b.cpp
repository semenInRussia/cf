// semenInRussia 2024
#include <cmath>
#include <cstdint>
#include <iomanip>
#include <iostream>
using namespace std;

using ld = long double;
const ld inf = 1e18 + 5;
const int L = 5;

template <typename T> T &setmin(T &v, T op) { return v = min(v, op); }

ld dist(pair<int, int> a, pair<int, int> b) {
  return hypot(abs(a.first - b.first), abs(a.second - b.second));
}

pair<int, int> p[L] = {
    {0, 0}, {+1, 0}, {0, -1}, {-1, 0}, {0, +1},
};

ld dist(int i, int j) { return dist(p[i], p[j]); }

string h = " RDLU";

int id(char c) {
  for (int i = 0; i < L; i++) {
    if (h[i] == c) {
      return i;
    }
  }
  return -1;
}

ld dist2(int i, int j, int i2, int j2) { return dist(i, i2) + dist(j, j2); }

const int N = 2e5;
ld f[N][L][L];

int main() {
  int n;
  cin >> n;

  for (int i = 0; i <= n; i++) {
    for (int a = 0; a < L; a++) {
      for (int b = 0; b < L; b++) {
        f[i][a][b] = +inf;
      }
    }
  }

  f[0][0][0] = 0;

  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;

    if (k == 1) {
      char c;
      cin >> c;

      int j = id(c);

      // either f[...][j], either f[j][...]
      for (int a = 0; a < L; a++) {
        for (int b = 0; b < L; b++) {
          if (f[i][a][b] == +inf) {
            continue;
          }
          for (int k = 0; k < L; k++) {
            setmin(f[i + 1][k][j], f[i][a][b] + dist2(a, b, k, j));
            setmin(f[i + 1][j][k], f[i][a][b] + dist2(a, b, j, k));
          }
        }
      }
    } else if (k == 2) {
      char c1, c2;
      cin >> c1 >> c2;
      int j1 = id(c1);
      int j2 = id(c2);

      for (int a = 0; a < L; a++) {
        for (int b = 0; b < L; b++) {
          if (f[i][a][b] == +inf) {
            continue;
          }
          setmin(f[i + 1][j1][j2], f[i][a][b] + dist2(j1, j2, a, b));
          setmin(f[i + 1][j2][j1], f[i][a][b] + dist2(j2, j1, a, b));
        }
      }
    }
  }

  ld ans = inf;
  for (int a = 0; a < L; a++) {
    for (int b = 0; b < L; b++) {
      setmin(ans, f[n][a][b]);
    }
  }

  cout << fixed << setprecision(12);
  cout << ans << "\n";
}
