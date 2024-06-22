// semenInRussia 2024
// https://codeforces.com/contest/1981/problem/C
#include <iostream>
using namespace std;
#define sz __lg
bool ispref(int p, int x) {
  int np = sz(p), nx = sz(x);
  if (np > nx)
    return false;
  return p == (x >> (nx - np));
}
const int maxn = 3e5;
int a[maxn];
void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  int y = -1, iy;
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] == -1)
      continue;
    if (y == -1) // fill from i to the end
      for (int j = i + 1; j < n; j++)
        a[j] = (a[j - 1] == 1) ? 2 : (a[j - 1] / 2);
    else {
      // assert(y != -1);
      for (int j = i + 1; j < iy; j++) {
        a[j] = a[j - 1];
        if (ispref(a[j], y)) { // add 0or1 to the end
          a[j] *= 2;
          a[j] += (y >> max(0, sz(y) - sz(a[j - 1]) - 1)) & 1;
        } else // remove
          a[j] /= 2;
      }
      if (abs(sz(a[iy - 1]) - sz(y)) != 1 ||
          !(ispref(a[iy - 1], y) || ispref(y, a[iy - 1]))) {
        cout << "-1\n";
        return;
      }
    }
    y = a[i], iy = i;
  }
  if (y == -1) { // all is -1
    a[0] = 1;
    for (int i = 1; i < n; i++)
      a[i] = (1 + 2) - a[i - 1];
  }
  if (a[0] == -1) // fill 0..iy
    for (int j = iy - 1; j >= 0; j--)
      a[j] = (a[j + 1] == 1) ? 2 : (a[j + 1] / 2);
  for (int i = 0; i < n; i++)
    cout << a[i] << ' ';
  cout << '\n';
}

int main() {
  int tt;
  cin >> tt;
  while (tt--)
    solve();
}
