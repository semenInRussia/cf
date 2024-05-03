// Copyright 2024 semenInRussia

#include <cinttypes>
#include <cstdio>
#include <ios>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);

  auto fp = stdin;

  // 2 * 10^6
  char c_str[2000000];
  char c_needle[2000000];

  fscanf(fp, "%s\n%s\n", c_str, c_needle);

  string str{c_str};
  string needle{c_needle};

  size_t n = str.size();

  size_t mult = needle.size() / str.size() + 1;

  // 10^6 -> 2*10^8

  while (mult--) {
    str.append(c_str);
  }

  size_t counted = 0;
  size_t pos = str.find(needle, 0);

  while (pos < n) {
    counted++;
    pos = str.find(needle, pos + 1);
  }

  cout << counted << endl;

  return 0;
}
