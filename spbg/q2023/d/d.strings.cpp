// Copyright 2024 semenInRussia

#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <set>
#include <vector>

using namespace std;

string normal(string &s) {
  size_t l = 0;
  while (s[l] == '0') {
    l++;
  }
  size_t r = s.size() - 1;
  while (s[r] == '0') {
    r--;
  }
  return s.substr(l, r - l + 1);
}

set<string> cnt(size_t sz) {
  set<string> nums;

  for (size_t i = 1; i <= sz; i++) {
    string x = "";
    size_t t = i;
    while (t--) {
      x.append("1");
    }
    nums.insert(x);
  }

  for (size_t i = 1; i < sz; i++) {
    string x = "";
    size_t t = i;
    while (t--) {
      x.append("1");
    }

    for (size_t zs = 1; zs < sz; zs++) {
      string nx = x;
      size_t t = zs;
      while (t--) {
        nx.append("0");
      }
      nx.append("1");
      nx = normal(nx);

      if (nx.size() > sz)
        break;
      nums.insert(nx);
    }
  }

  return nums;
}

int main() {
  size_t a, b, c;
  cin >> a >> b >> c;

  auto xs = cnt(lcm(a, b));

  for (auto x : xs) {
    cout << x << endl;
  }

  return 0;
}
