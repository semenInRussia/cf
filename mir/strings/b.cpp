// Copyright 2024 semenInRussia

#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  string s;
  cin >> s;
  reverse(s.begin(), s.end());

  int res = 0;
  int m = 1;

  int i = 0;
  while (i < n) {
    int dig = 0;
    // count ones
    while (i < n && s[i] == '1') {
      i++;
      dig++;
    }
    // add to res using m (10s coefficient)
    res += m * dig;
    m *= 10;

    i++;
  }

  cout << res << endl;

  return 0;
}
