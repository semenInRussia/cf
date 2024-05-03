// Copyright 2023 semenInRussia: tests

using namespace std;

#include <cstdint>

#include <ctype.h>
#include <fstream>
#include <iostream>
#include <vector>

int main() {
  int sz = -100'000;

  vector<int> a(1000);
  a.push_back(1);
  a.pop_back();
  a.push_back(1);
  a.pop_back();

  int ft = a.front();
  a.resize(ft);

  cout << sz << endl;
  return 0;
}
