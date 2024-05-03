// Copyright 2024 semenInRussia

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main() {
  string a, b;
  cin >> a >> b;
  size_t sz = max(a.size(), b.size());
  a.insert(0, string(sz - a.size(), '0'));
  b.insert(0, string(sz - b.size(), '0'));
  cout << a << endl;
  cout << b << endl;
  cout << a.compare(b) << endl;
}
