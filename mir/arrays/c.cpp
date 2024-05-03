// Copyright 2024 semenInRussia

#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  size_t n;
  cin >> n;

  // : x > prev
  int prev = INT32_MIN, curlen = 0, maxlen = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x > prev) {
      curlen++;
      maxlen = max(curlen, maxlen);
    } else {
      curlen = 1;
    }
    prev = x;
  }

  cout << maxlen << '\n';

  return 0;
}
