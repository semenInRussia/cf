// Copyright 2023 semenInRussia

#include <algorithm>
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
  size_t n, A, B;
  cin >> n >> A >> B;

  vector<long> t;

  for (size_t i = 0; i < n; i++) {
    long el;
    cin >> el;
    if (el >= 0) {
      t.push_back(el);
    }
  }

  if (t.empty()) {
    cout << '0' << endl;
    return 0;
  }

  if (A > B) {
    size_t iters = 0;

    while (1) {
      auto mxi = imax(t);
      if (t[mxi] < 0) {
        break;
      }

      t[mxi] -= A;
      for (size_t j = 0; j < t.size(); j++) {
        if (j != mxi) {
          t[j] -= B;
        }
      }

      iters++;
    }

    cout << iters << endl;

    return 0;
  }

  if (A == B) {
    size_t mx = t[imax(t)];
    cout << iters_for(mx, A) << endl;

    return 0;
  }

  if (A <= B) {
    // Strategy:
    // find mni;
    // t[mni] -= A
    size_t iters = 0;

    while (t[imax(t)] > 0) {
      auto mni = imin(t);
      t[mni] -= A;

      for (size_t j = 0; j < t.size(); j++) {
        if (j != mni) {
          t[j] -= B;
        }
      }

      iters++;
    }

    cout << iters << endl;

    return 0;
  }
}
