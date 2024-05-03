// Copyright 2024 semenInRussia

using namespace std;

#include <iostream>

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    cout << ((k >= n - 1) ? 1 : n) << endl;
  }

  return 0;
}
