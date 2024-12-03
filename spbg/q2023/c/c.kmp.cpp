// Copyright 2024 semenInRussia

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> z_function(string s);

int main() {
  string str, needle;
  cin >> str >> needle;

  int mult = needle.size() / str.size() + 1;

  string big_str = str;
  while (mult--)
    big_str += str;

  int k = needle.size();
  int n = str.size();

  vector<int> zp = z_function(needle + "|" + big_str);

  int cnt = 0;

  auto mtch = find(zp.begin(), zp.end(), k);

  while (mtch != end(zp)) {
    // needle and a character like "|" is inserted before strign, in
    // KMP algo
    int pos = distance(zp.begin(), mtch) - k - 1;
    if (pos >= n)
      break;
    cnt++;
    mtch = find(mtch + 1, zp.end(), k);
  }

  cout << cnt << endl;

  return 0;
}

vector<int> z_function(string s) {
  int n = s.length();
  int ans = n;
  vector<int> z(n);
  int l = 0, r = 0;

  for (int i = 1; i < n; ++i) {
    if (i <= r)
      z[i] = min(r - i + 1, z[i - l]);
    while (i + z[i] < n && s[z[i]] == s[i + z[i]])
      z[i]++;
    if (i + z[i] - 1 > r)
      l = i, r = i + z[i] - 1;
  }
  return z;
}
