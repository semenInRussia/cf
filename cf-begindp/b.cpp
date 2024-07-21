// semenInRussia 2024
#include <cassert>
#include <cstdio>
#include <iostream>
using namespace std;

const int N = 1000, inf = 1e9, P = 3;
int f[N], a[N], ps[3] = {1, 3, 5};
int main() {
  freopen("lepus.in", "r", stdin);
  freopen("lepus.out", "w", stdout);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    char ch;
    cin >> ch;
    if (ch == '"')
      a[i] = 1;
    else if (ch == 'w')
      a[i] = -1;
    else if (ch == '.')
      a[i] = 0;
    else
      assert(0 && "unreac");
  }

  for (int i = 0; i < n; i++) {
    f[i] = -1;
    int mx = i ? -1 : 0;
    for (int *p = ps; p != ps + P; p++)
      if (i - *p >= 0)
        mx = max(f[i - *p], mx);
    if (mx == -1 || a[i] == -1)
      continue;
    f[i] = a[i] + mx;
  }

  cout << f[n - 1];
}
