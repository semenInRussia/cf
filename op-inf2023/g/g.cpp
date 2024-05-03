// Copyright 2023 semenInRussia

#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

inline size_t iters_for(long temp, size_t k) {
  size_t div = temp / k;
  if (div * k <= temp) {
    return div + 1;
  } else {
    return div;
  }
}

size_t imax(vector<long> &arr, size_t exception = -1) {
  size_t imx = exception ? 0 : 1;

  for (size_t i = imx + 1; i < arr.size(); i++) {
    if (arr[i] > arr[imx]) {
      imx = i;
    }
  }
  return imx;
}

size_t imin(vector<long> &arr, size_t exception = -1) {
  size_t imn = exception ? 0 : 1;

  for (size_t i = imn + 1; i < arr.size(); i++) {
    if (arr[imn] > 0 && arr[imn] > arr[i]) {
      imn = i;
    }
  }

  return imn;
}

int main() {
  vector<long> t = {1, 3, 7, 2};

  cout << max(t.begin(), t.end()) << endl;
}
