// Copyright 2024 semenInRussia

using namespace std;

#include <bitset>
#include <iostream>
#include <vector>

int main() {
  bitset<64> a = 0;

  a[5] = 1;
  cout << a.to_ullong() << endl;
}
