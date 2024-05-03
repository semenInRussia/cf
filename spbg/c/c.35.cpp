// Copyright 2024 semenInRussia

#include <algorithm>
#include <ios>
#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);

  string str, needle;
  cin >> str >> needle;

  size_t mult = needle.size() / str.size() + 1;
  string s = str;

  while (mult--) {
    str += s;
  }

  size_t n = s.size();

  size_t counted = 0;
  size_t pos = str.find(needle, 0);

  while (pos != string::npos && pos < n) {
    counted++;
    pos = str.find(needle, pos + 1);
  }

  cout << counted << endl;

  return 0;
}
