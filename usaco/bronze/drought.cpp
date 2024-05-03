// Copyright 2024 semenInRussia

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
  int n;
  cin >> n;

  // k[0] = 0
  // t == a[0] - k[0] - k[1]
  // ...
  // t == a[i] - k[i] - k[i]
  // ...
  // t == a[n-1] - k[n-1] - k[0]

  // tn == sum(a) - 2sum(k)
  // 2sum(k) == sum(a) - tn

  vector<int> a(n);
  int suma = 0;
  for (auto &x : a)
    cin >> x, suma += x;

  int mx = *max_element(a.begin(), a.end());
  for (int t = mx; t >= 0; t--) {
    int sumk = (suma - t * n);
    if (sumk > 0 && sumk % 2 == 0) {
      cout << t << ' ' << sumk << '\n';
      return;
    }
  }
  cout << "-1" << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
}
