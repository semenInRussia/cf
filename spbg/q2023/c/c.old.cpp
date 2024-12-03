// Copyright 2024 semenInRussia

#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  string str, needle;
  cin >> str >> needle;

  // size_t mult = needle.size() / str.size();

  // if (mult) {
  //   string s = str;
  //   for (size_t i = 0; i < mult; i++) {
  //     str += s;
  //   }
  // }

  size_t counted = 0;
  size_t pos = 0;
  size_t f = str.find(needle, pos);

  while (f != string::npos) {
    counted++;
    pos = f + 1;
    f = str.find(needle, pos);
  }

  string rst = str.substr(pos) + str.substr(0, needle.size() - 1);

  pos = rst.find(needle);

  while (pos != string::npos) {
    counted++;
    pos = rst.find(needle, pos + 1);
  }

  cout << counted << endl;

  return 0;
}
