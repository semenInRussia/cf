// Copyright 2024 semenInRussia

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
  int n;
  cin >> n;
  vector<int> d(n);
  for (auto &x : d)
    cin >> x;
  sort(d.begin(), d.end());
  cout << (d[0] + d[1]) << endl;
}
