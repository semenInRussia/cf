// semenInRussia 2024
// https://codeforces.com/contest/858/problem/B
#include <cassert>
#include <iostream>
using namespace std;

const int N = 150;
int f[N], k[N];

int a(int f, int k) { return (k + f - 1) / f; }

int b(int f, int k) {
  f--;
  if (f == 0)
    return 101;
  return (k - 1 + f - 1) / f;
}

int main() {
  int n, m;
  cin >> n >> m;
  int mn = 0, mx = n;
  for (int i = 0; i < m; i++) {
    cin >> f[i] >> k[i];
    // k[i] is first on floor f[i]
    // (f[i] - 1) * mn + 1 = k[i]
    //
    // f[i] * mx = k[i]

    // 5
    // 3
    mn = max(mn, a(f[i], k[i]));
    mx = min(mx, b(f[i], k[i]));
  }
  int ans = -1;
  for (int i = 1; i <= n; i++) {
    if (a(i, n) > mx || b(i, n) < mn)
      continue;
    if (ans != -1) {
      ans = -1;
      break;
    }
    ans = i;
  }
  cout << ans;
}
