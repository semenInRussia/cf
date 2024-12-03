// semenInRussia 2024
#include <iostream>
using namespace std;

const int mod = 998244353;
const int N = 510;
int f[N][N];

int main() {
  int n, m;
  cin >> n >> m;

  // f[i][j] - amount of ways with n=i, m=j
  for (int i = 0; i < n; i++) {
    f[i][0] = 1;
  }
  for (int j = 0; j < m; j++) {
    f[0][j] = 1;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      // add
    }
  }
}
