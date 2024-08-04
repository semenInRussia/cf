// semenInRussia 2024
#include <iostream>
using namespace std;
const int mod = 1e9 + 7;
#pragma GCC optimize("Ofast,unroll-loops")

const int N = 2e5 + 1;
int f[N]; // f[i] - ways to do i

int main() {
  int a, b;
  cin >> a >> b;
  int n = a + b;
  int lev = 0;
  while (lev * (lev + 1) <= 2 * n)
    lev++;
  lev--;
  if (a > b)
    swap(a, b);

  f[0] = 1;
  for (int l = 1; l <= lev; l++)
    for (int i = a; i > 0; i--)
      if (i >= l && f[i - l])
        f[i] = (f[i] + f[i - l]) % mod;

  int w = lev * (lev + 1) / 2;
  int ans = 0;
  for (int ax = max(0, w - b); ax <= a; ax++)
    ans = (ans + f[ax]) % mod;
  cout << ans;
}
