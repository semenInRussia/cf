// semenInRussia 2024
#include <iostream>
using namespace std;

const int N = 2e5;
unsigned long long f[N][4];

int main() {
  int n;
  cin >> n;
  f[1][2] = 1;
  for (int i = 2; i <= n; i++) {
    f[i][0] = f[i - 1][2] * 2;
    f[i][1] = f[i - 1][2];
    f[i][2] = f[i - 1][3] + f[i - 1][1];
    f[i][3] = f[i - 1][2];
  }

  cout << f[n][0];
}
