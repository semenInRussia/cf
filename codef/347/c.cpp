// Copyright 2024 semenInRussia

#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, a, b;
  cin >> n >> a >> b;

  vector<int> d(n);
  for (auto &x : d)
    cin >> x;

  int w = a + b;
  bool ok = true;
  for (auto x : d)
    ok &= ((x - 1) % w) <= a - 1;
  cout << (ok ? "Yes\n" : "No\n");
}
