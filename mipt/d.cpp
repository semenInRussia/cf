// Copyright 2024 semenInRussia

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
  string typ, s;
  cin >> typ >> s;
  int n = (int)s.size();
  if (typ == "encode") {
    if (n & 1)
      s = s.substr(0, n / 2) + s[n / 2] + s.substr(n / 2);
    cout << s << endl;
    return 0;
  } else {
    assert(typ == "decode");
    for (int i = 0; i < n; i++)
      if (s[i] == '?')
        s[i] = s[n - 1 - i];
    cout << s << endl;
    return 0;
  }
}
