// Copyright 2024 semenInRussia

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

using ll = long long;
using ull = unsigned long long;
const int inf = 1e9;

const int maxn = 501;
int x[maxn], a[maxn];

void solve() {
  int n;
  cin >> n;

  for (int i = 1; i < n; i++)
    cin >> x[i];

  // x_i = a_i \bmod a_{i-1}
  // a_i = x_i \bmod a_{i-1}

  for (int g = *max_element(x, x + n) + 1; g < 1e5; g++) {
    bool ok = true;
    a[0] = g;
    for (int i = 1; i < n; i++) {
      if (a[i - 1] == 0) {
        ok = false;
        break;
      }
      // x[i] = (a[i] % a[i-1])
      // x[i] - a[i] = 0 % a[i-1]
      a[i] = x[i] % a[i - 1] + a[i - 1];
    }
    if (ok)
      break;
  }

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
