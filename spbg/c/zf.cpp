// Copyright 2024 semenInRussia

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<size_t> z_function(string s);

int main() {
  string str = "abaabaaba";
  string needle = "abaab";

  auto zp = z_function(needle + "|" + str);

  auto mtch = find(zp.begin(), zp.end(), needle.size());

  cout << "Matches:" << endl;

  while (mtch != end(zp)) {
    size_t pos = distance(zp.begin(), mtch) - needle.size() - 1;
    if (pos >= str.size()) {
      break;
    }
    cout << pos << endl;
    mtch = find(mtch + 1, zp.end(), needle.size());
  }

  for (auto x : zp) {
    cout << x << ' ';
  }

  cout << endl;

  for (size_t i = 0; i < zp.size(); ++i) {
    cout << i << ' ';
  }

  cout << endl;

  return 0;
}

vector<size_t> z_function(string s) {
  size_t n = s.length();

  vector<size_t> z(n);
  size_t l = 0, r = 0;

  for (size_t i = 1; i < n; ++i) {
    if (i <= r) {
      z[i] = min(r - i + 1, z[i - l]);
    }
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
      ++z[i];
    }
    if (i + z[i] - 1 > r) {
      l = i;
      r = i + z[i] - 1;
    }
  }
  return z;
}
