// Copyright 2024 semenInRussia
// https://codeforces.com/problemset/problem/1956/C
// #constructive *1600
#include <iostream>
using namespace std;
using ll = long long;

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    ll n;
    cin >> n;
    int a[502][502];
    for (int i = n; i >= 1; i--) {
      for (int j = 1; j <= n; j++)
        a[i][j] = j;
      for (int j = 1; j <= n; j++)
        a[j][i] = j;
    }
    ll s = 0;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        s += a[i][j];

    cout << s << ' ' << (2 * n) << '\n';
    for (int i = n; i >= 1; i--) {
      cout << "1 " << i << ' ';
      for (int j = 1; j <= n; j++)
        cout << j << ' ';
      cout << "\n2 " << i << ' ';
      for (int j = 1; j <= n; j++)
        cout << j << ' ';
      cout << '\n';
    }
  }
}
