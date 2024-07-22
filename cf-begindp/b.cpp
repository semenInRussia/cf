// semenInRussia 2024
#include <cassert>
#include <cstdio>
#include <iostream>
using namespace std;

const int N = 1000, inf = 1e9;
int f[N], a[N];
int main() {
  freopen("lepus.in", "r", stdin);
  freopen("lepus.out", "w", stdout);
  string s;
  int n;
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    f[i] = -1;
    int mx = i ? -1 : 0;
    for (int p : {1, 3, 5})
      if (i - p >= 0)
        mx = max(f[i - p], mx);
    if (mx == -1 || s[i] == 'w')
      continue;
    f[i] = (s[i] == '\"') + mx;
  }

  cout << f[n - 1];
}
