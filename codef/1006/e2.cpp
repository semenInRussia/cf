// semenInRussia 2025
#include <cstdint>
#include <iostream>

using namespace std;

const int N = 20;
int t[N][N];

int main() {
  t[0][0] = 1;
  for (int i = 1; i < N; i++) {
    for (int j = 0; j <= i; j++) {
      if (j == 0) {
        t[i][j] = t[i - 1][j];
      } else if (j == i) {
        t[i][j] = t[i - 1][j - 1];
      } else {
        t[i][j] = t[i - 1][j - 1] ^ t[i - 1][j];
      }
      if (j == 7) {
        cout << t[i][j] << "";
      }
    }
    // cout << res;
    cout << "\n";
  }
}
