// semenInRussia 2024
// https://cses.fi/problemset/task/1635
#include <iostream>
using namespace std;

const int N = 100, X = 1e6 + 100, mod = 1e9 + 7;
int c[N], f[X];

int main() {
  int n, x;
  cin >> n >> x;
  for (int i = 0; i < n; i++)
    cin >> c[i];

  f[0] = 1;
  for (int s = 1; s <= x; s++) {
    for (int i = 0; i < n; i++) {
      if (c[i] <= s)
        f[s] += f[s - c[i]], f[s] %= mod;
    }
  }
  cout << f[x];
}
