// semenInRussia 2024
#include <cassert>
#include <cstdio>
#include <iostream>
using namespace std;

const int N = 105, inf = 1e9;
int f[N], a[N];
int main() {
  freopen("ladder.in", "r", stdin);
  freopen("ladder.out", "w", stdout);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i], f[i] = -inf;
  f[0] = a[0];
  if (n > 1)
    f[1] = a[1];
  for (int i = 1; i < n; i++) {
    assert(i <= 1 || f[i] == -inf);
    if (i >= 2)
      f[i] = max(f[i], a[i] + f[i - 2]);
    f[i] = max(f[i], a[i] + f[i - 1]);
  }
  cout << f[n - 1] << '\n';
}
