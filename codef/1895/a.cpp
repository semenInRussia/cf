// Copyright 2023 semenInRussia

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  size_t t;
    
  while (t--) {
    size_t x, y, k;
    cin >> x >> y >> k;
    
    if (x < y) {
      size_t d = y - x;
      size_t to_y = d > k ? k + (d - k) * 2 : d;
      cout << x + to_y << endl;
    } else {
      cout << x << endl;
    }
  }

  return 0;
}
