// Copyright 2024 semenInRussia

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<size_t> z_function(string s);

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);

  string str, needle;
  cin >> str >> needle;

  size_t mult = needle.size() / str.size() + 1;

  string big_str = str;
  while (mult--) {
    big_str += str;
  }

  size_t k = needle.size();
  size_t n = str.size();

  vector<size_t> zp = z_function(needle + "|" + big_str);

  size_t counted = 0;

  auto mtch = find(zp.begin(), zp.end(), k);

  while (mtch != end(zp)) {
    // needle and a character like "|" is inserted before strign, in
    // KMP algo
    size_t pos = distance(zp.begin(), mtch) - k - 1;
    if (pos >= n) {
      break;
    }
    counted++;
    mtch = find(mtch + 1, zp.end(), k);
  }

  cout << counted << endl;

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
