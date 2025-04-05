// semenInRussia 2025
#include <cstdint>
#include <iostream>

using namespace std;

const int M = 11;
int p[M];

int64_t f1[1 << 18], f2[1 << 18];

inline int get(int b, int j) { return (b >> (2 * j)) % 4; }

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
#ifndef home
  freopen("dominoes.in", "r", stdin);
  freopen("dominoes.out", "w", stdout);
#endif
  int n, m;
  cin >> n >> m;

  p[0] = 1;
  for (int i = 1; i <= n; i++) {
    p[i] = p[i - 1] * 4;
  }

  f1[0] = 1;
  for (int j = 0; j < m; j++) {
    for (int i = 0; i < n; i++) {
      for (int b = 0; b < p[n]; b++) {
        // add nothing
        f2[b] += f1[b];

        // add horizontal domino, from 0=>3
        if (get(b, i) == 0) {
          f2[b + p[i] * 3] += f1[b];
        }

        // add vertical domino, from 000=>111
        if (i + 3 <= n && get(b, i) == 0 && get(b, i + 1) == 0 &&
            get(b, i + 2) == 0) {
          f2[b + p[i] + p[i + 1] + p[i + 2]] += f1[b];
        }
      }

      swap(f1, f2);
      fill(f2, end(f2), 0);
    }

    for (int b = 0; b < p[n]; b++) {
      bool ok = true;
      int b2 = b;
      for (int i = 0; i < n; i++) {
        if (get(b, i) == 0) {
          ok = false;
          break;
        }
        b2 -= p[i];
      }

      if (ok) {
        f2[b2] = f1[b];
      }
    }

    swap(f1, f2);
    fill(f2, end(f2), 0);
  }

  cout << f1[0];
}
