// semenInRussia 2024
// https://cses.fi/problemset/task/2181
#include <iostream>
using namespace std;

const int N = 20, mod = 1e9 + 7;
int f[1 << N], f2[1 << N];

int main() {
  int n, m;
  cin >> n >> m;
  f[0] = 1;
  for (int j = 0; j < m; j++) {
    for (int i = 0; i < n; i++) {
      for (int b = 0; b < (1 << n); b++) {
        f2[b] = f[b ^ (1 << i)];
        if (i && !(b & (1 << i)) && !(b & (1 << (i - 1)))) {
          f2[b] += f[b ^ (1 << (i - 1))];
          f2[b] %= mod;
        }
      }
      for (int b = 0; b < (1 << n); b++) {
        f[b] = f2[b];
      }
    }
  }
  cout << f[0];
}
