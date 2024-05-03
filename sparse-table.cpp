// Copyright 2023 semenInRussia

using namespace std;

#include <cmath>
#include <vector>

#include <iostream>

vector<vector<int>> build_sparse(vector<int> arr) {
  size_t n = arr.size();
  size_t maxpow = ceil(log2(arr.size()));

  vector<vector<int>> tbl(maxpow, vector<int>(n));
  // every minimum element from segments from 1 element, it's the first element.
  // --
  // here every minimum from 1element arrays from begin at indexes are
  // values at indexes
  tbl[0] = arr;

  for (size_t k = 0; k + 1 < maxpow; k++) {
    for (size_t beg = 0; beg + (1 << (k + 1)) <= arr.size(); beg++) {
      // 0 => 2
      // 1 => 4
      // 2 => 8
      // 3 => 16
      // els = 1 << (i + 1)
      tbl[k + 1][beg] = min(tbl[k][beg], tbl[k][beg + (1 << k)]);
    }
  }

  return tbl;
}

int main() {
  std::vector<int> arr = {1, 5, 9, 8, 7, 6, 3, 8};
  std::vector<std::vector<int>> table = build_sparse(arr);

  std::size_t i = 0;

  for (auto &row : table) {
    for (auto &el : row) {
      std::cout << el << ' ';
    }
    std::cout << std::endl;
  }

  return 0;
}
