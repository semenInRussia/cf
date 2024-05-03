// Copyright 2024 semenInRussia

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int a, b;
  cin >> a >> b;

  vector<int> arr(a + b);

  for (auto x : arr) {
    cin >> x;
  }

  while (a > b) {
    a++ && (b--);
  }

  cout << (a - b);

  return 0;
}
