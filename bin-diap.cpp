// Copyright 2024 semenInRussia

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (auto &x : a)
    cin >> x;
  sort(a.begin(), a.end());

  int k;
  cin >> k;

  for (int z = 0; z < k; z++) {
    int l, r;
    cin >> l >> r;

    auto li = lower_bound(a.begin(), a.end(), l);
    auto ri = upper_bound(a.begin(), a.end(), r);
    cout << (ri - li) << '\n';
  }
}
