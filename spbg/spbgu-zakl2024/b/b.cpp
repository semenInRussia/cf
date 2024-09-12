// Copyright 2024 semenInRussia

#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int compute(pair<int, int> a, pair<int, int> b) {
  int x1 = a.first;
  int x2 = b.first;
  int y1 = a.second;
  int y2 = b.second;
  return abs(x1 + y1 - x2 - y2) + min(abs(x2 - x1), abs(y2 - y1));
}

int main() {
  int n, x1, y1, z1, x2, y2, z2;
  cin >> n >> x1 >> y1 >> z2 >> x2 >> y2 >> z2;

  vector<pair<int, int>> ps = {
      {x1, x2},
      {y1, y2},
      {z2, x2},
  };

  int res = INT32_MAX;

  for (int i = 0; i < 3; i++) {
    for (int j = i + 1; j < 3; j++) {
      res = min(res, compute(ps[i], ps[j]));
    }
  }

  cout << res << endl;

  return 0;
}
