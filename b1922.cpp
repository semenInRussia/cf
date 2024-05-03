// Copyright 2024 semenInRussia
// https://codeforces.com/contest/1922/problem/B
//
// sorting, binsearch

using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>

void solve() {
  size_t n;
  cin >> n;

  vector<size_t> a(n);

  for (auto &x : a)
    cin >> x;

  sort(a.begin(), a.end());

  size_t result = 0;

  for (int i = (int)(n - 1); i >= 2; i++) {
    // find j, that a(i-1) + a(j) > a(i)
    int l = 0;
    int r = i - 1;

    size_t x = a[i];
    size_t y = a[i - 1];

    while (r > l + 1) {
      size_t j = (r - l) / 2 + l;
      size_t z = a[j];

      // ok: x < y + z

      if (x < y + z) {
        r = j;
      } else {
        l = j;
      }
    }

    result += (i - 1) - r;
  }

  cout << result << endl;
}

int main() {
  size_t t;
  cin >> t;

  while (t--)
    solve();

  return 0;
}
