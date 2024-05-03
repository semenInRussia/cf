// Copyright 2024 semenInRussia

#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> a(n);
  for (auto &x : a)
    cin >> x;

  for (auto x : a)
    if (x % k == 0)
      cout << (x / k) << ' ';
}
