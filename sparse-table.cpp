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
