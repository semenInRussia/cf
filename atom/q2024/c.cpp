// semenInRussia 2024
// https://contest.yandex.ru/contest/69757/problems/%D0%A1/
#include <iostream>
using namespace std;

const int N = 1e5 + 10, C = 4;
const int mod = 1e9 + 7;

int f[N][C]; // answer for i walls that last colors is given

int can[C][C];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < C; i++) {
    for (int j = 0; j < C; j++) {
      cin >> can[j][i];
    }
  }

  for (int c = 0; c < C; c++) {
    f[0][c] = 1;
  }

  for (int i = 1; i < n; i++) {
    for (int prv = 0; prv < C; prv++) {
      for (int c = 0; c < C; c++) {
        if (can[prv][c]) { // on i=0 no check
          (f[i][c] += f[i - 1][prv]) %= mod;
        }
      }
    }
  }

  int ans = 0;
  for (int c = 0; c < C; c++) {
    (ans += f[n - 1][c]) %= mod;
  }
  cout << ans;
}
