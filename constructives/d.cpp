// semenInRussia 2025
#include <cstdint>
#include <iostream>

using namespace std;

const int N = 1005;
int v[N][N], a[N][N];

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> a[i][j];
      }
    }

    int ans = 0;

    for (int k = 0; k < 30; k++) {
      for (int j = 0; j < n; j++) {
        v[0][j] = 0;
      }

      int o = 0; // ones (0-even, 1-odd)

      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          o ^= (v[i][j] >> k) & 1;
          int x = a[i][j];
          if (i > 0) {
            x ^= v[i - 1][j];
          }
          if (j > 0) {
            x ^= v[i][j - 1];
          }

          // right already computed
          if (j + 1 < n) {
            x ^= v[i][j + 1];
          }

          v[i + 1][j] = x;
        }
      }

      if (o) {
        ans |= 1 << k;
      }
    }

    cout << ans << "\n";
  }
}
