// Copyright 2024 semenInRussia
#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;

void solve() {
  int a, b, c;
  cin >> a >> b >> c;

  int arr[] = {a, b, c};
  sort(arr, arr + 3);
  a = arr[0], b = arr[1], c = arr[2];

  int ans = a;
  while (a--) {
    if (b > c)
      b--;
    else
      c--;
  }
  ans += min(b, c);

  if ((c - b) & 1)
    cout << "-1\n";
  else
    cout << ans << '\n';
}

int main() {
  int tt;
  cin >> tt;
  while (tt--)
    solve();
}
