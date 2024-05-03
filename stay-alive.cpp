// Copyright 2023 semenInRussia
//
// https://codeforces.com/problemset/problem/1879/F

#include <iostream>
#include <vector>

using namespace std;

void test_case() {
  size_t hero_amnt;

  cin >> hero_amnt;

  vector<size_t> h;

  for (size_t i = 0; i < hero_amnt; i++) {
    cin >> h[i];
  }

  vector<size_t> a;

  for (size_t i = 0; i < hero_amnt; i++) {
    cin >> a[i];
  }

  for (size_t i = 0; i < hero_amnt; i++) {
    // find the best X for i'th hero
    //
    // find an integer which is divided by (a - 1)
  }
}

int main() {
  size_t t;

  cin >> t;

  while (t--) {
    test_case();
  }

  return 0;
}
