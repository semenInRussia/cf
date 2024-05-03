// Copyright 2024 semenInRussia
//
// https://codeforces.com/contest/1783/problem/C
// *1700

#include <algorithm>
#include <functional>
#include <iostream>

using namespace std;

const int maxn = 6e5;
int a[maxn], w[maxn];

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
      cin >> a[i];
    sort(a, a + n);

    // w[i] is amount of wins that i can do
    int tot = 0;
    w[0] = 0;
    for (int i = 1; i < n; i++) {
      tot += a[i - 1] != a[i];
      w[i] = tot;
    }
    for (int i = 0; i < n; i++)
      w[i] += a[i] > m;

    int wins = 0;
    int rst = m;
    for (int i = 0; i < n && rst > 0; i++) {
      wins += rst >= a[i];
      rst -= a[i];
    }

    sort(w, w + n, greater<int>());
    // place of wins is answer

    int i = 0;
    while (w[i] > wins && i < n)
      i++;

    cout << (i + 1) << endl;
  }
}
