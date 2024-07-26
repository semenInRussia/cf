// semenInRussia 2024
#include <iostream>
using namespace std;

using ll = long long;
const int maxn = 44;
ll f[maxn + 1];

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  // --

  ll n;
  cin >> n;
  f[0] = f[1] = 1;
  for (int i = 2; i < maxn; i++)
    f[i] = f[i - 1] + f[i - 2];
  int j = lower_bound(f, f + maxn, n) - f;
  if (j == maxn || f[j] != n)
    cout << -1;
  else if (n == 1)
    cout << 2;
  else
    cout << j + 1;
}
