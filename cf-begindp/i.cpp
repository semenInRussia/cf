// semenInRussia 2024
#include <iostream>
using namespace std;
const int N = 302, S = 10002;
int a[N];
bool f[N][S];
int main() {
  int s, n;
  cin >> s >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  // f[i][w] is true when we can buy w using <i things
  f[0][0] = true;
  for (int i = 0; i < n; i++) {
    f[i + 1][0] = true;
    for (int w = 0; w <= s; w++) {
      f[i + 1][w] = f[i][w];
      if (w >= a[i])
        f[i + 1][w] = f[i + 1][w] || f[i][w - a[i]];
    }
  }
  int ans = 0;
  for (int w = 0; w <= s; w++)
    if (f[n][w])
      ans = w;
  cout << ans;
}
