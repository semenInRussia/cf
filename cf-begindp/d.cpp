// semenInRussia 2024
#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
const int N = 8, inf = 1e9;
int f[N][N], a[N][N];

int main() {
  freopen("king2.out", "w", stdout);
  freopen("king2.in", "r", stdin);
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      cin >> a[i][j];
  for (int i = N - 1; i >= 0; i--) {
    for (int j = 0; j < N; j++) {
      // (i-1,j), (i-1,j-1), (i, j-1)
      if (!(i == N - 1 && j == 0))
        f[i][j] = +inf;
      for (int di : {+1, 0})
        for (int dj : {-1, 0})
          if (i + di < N && j + dj >= 0 && (di || dj))
            f[i][j] = min(f[i][j], a[i][j] + f[i + di][j + dj]);
    }
  }
  cout << f[0][N - 1];
}
