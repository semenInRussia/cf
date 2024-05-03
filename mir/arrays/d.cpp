// Copyright 2024 semenInRussia

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);

  for (auto &x : a)
    cin >> x;

  sort(a.begin(), a.end());
  int d = a[1] - a[0];
  for (int i = 1; i + 1 < n; i++) {
    d = min(a[i + 1] - a[i], d);
  }

  multiset<int> h;
  for (auto &x : a)
    h.insert(x);

  int cnt = 0;
  while (!h.empty()) {
    // consider x is min
    // d = y - x
    // y = x + d
    int x = *h.begin();
    cnt += h.count(x + d);
    h.erase(h.begin());
  }

  cout << d << ' ' << cnt << '\n';

  return 0;
}
