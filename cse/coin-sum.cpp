// semenInRussia 2024
// https://cses.fi/problemset/task/1634
#include <iostream>
using namespace std;

const int N = 100, X = 1e6 + 100, inf = 1e9 + 123;
int c[N], f[X];

int main() {
  int n, x;
  cin >> n >> x;
  for (int i = 0; i < n; i++)
    cin >> c[i];

  f[0] = 0;
  for (int s = 1; s <= x; s++) {
    f[s] = -1;
    for (int i = 0; i < n; i++) {
      if (c[i] <= s && f[s - c[i]] >= 0 &&
          (f[s] == -1 || f[s] > f[s - c[i]] + 1))
        f[s] = f[s - c[i]] + 1;
    }
  }
  cout << f[x];
}
