// semenInRussia 2024
// https://cses.fi/problemset/task/1633
#include <iostream>
using namespace std;

const int N = 1e6 + 1, mod = 1e9 + 7;
int f[N];

int main() {
  int n;
  cin >> n;
  f[0] = 1;
  for (int i = 1; i <= n; i++)
    for (int d = 1; d <= 6; d++)
      if (i >= d)
        f[i] += f[i - d], f[i] %= mod;

  cout << f[n];
}
