// Copyright 2023 semenInRussia

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int r;
  size_t sz = 5;

  for (size_t i = 0; i < 100; i++) {
    size_t x = sz * ((i + sz) / sz) - 1;
    cout << i << ": " << x << endl;
  }

  // for (size_t k = 0; k <= 100; k++) {
  //   cout << "k = " << k << ":" << endl;
  //   for (size_t i = 0; i < 16; i++) {
  //     cout << (i ^ k) << ' ';
  //   }
  //   cout << endl << endl;
  // }

  return 0;
}
