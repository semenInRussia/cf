// Copyright 2024 semenInRussia

#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  string wsen = "WSEN";
  cout << *max_element(wsen.begin(), wsen.end()) << ' ';
  cout << *min_element(wsen.begin(), wsen.end()) << ' ';
  return 0;
}
