// Copyright 2023 semenInRussia

#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <ranges>
#include <vector>

// t[ix1] - (iters - as[ix1])*B - as[ix1]*A;
#define val(i) (t[i] - (iters - as[i]) * B - as[i] * A)

using namespace std;

inline long iters_for(long temp, long k) {
  if (temp < 0) {
    return 0;
  }

  long div = temp / k;
  long p = div * k;
  if (p <= temp) {
    return div + 1;
  } else {
    return div;
  }
}

size_t imax(vector<long> &arr, size_t exception = -1) {
  size_t imx = exception ? 0 : 1;

  for (size_t i = imx + 1; i < arr.size(); i++) {
    if (arr[i] > arr[imx] && i != exception) {
      imx = i;
    }
  }
  return imx;
}

size_t imin(vector<long> &arr, size_t exception = -1) {
  size_t imn = exception ? 0 : 1;

  for (size_t i = imn + 1; i < arr.size(); i++) {
    if (arr[imn] > arr[i] && i != exception) {
      imn = i;
    }
  }

  return imn;
}

int main() {
  size_t n;
  long A, B;
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

  if (t.size() == 1) {
    cout << iters_for(t[0], A) << endl;
    return 0;
  }

  if ((B > A && t.size() < n) || A == B) {
    long mx = t[imax(t)];
    cout << iters_for(mx, B) << endl;

    return 0;
  }

  // O(log n)
  long sumt = accumulate(t.begin(), t.end(), 0);
  long lw_iters = sumt / (A + B * (t.size() - 1)) + 1;

  if (A > B || t.size() == 2) {
    if (A < B) {
      swap(A, B);
    }

    long hg_iters = iters_for(*max_element(t.begin(), t.end()), B);
    long mn_iters = hg_iters;

    while (lw_iters <= hg_iters) {
      // mid:
      long iters = (lw_iters + hg_iters) / 2;

      // check:
      long min_its = 0;

      for (auto ti : t) {
        if (ti >= B * iters) {
          min_its += (ti - B * iters) / (A - B) + 1;
        }
      }

      bool ok = min_its <= iters;

      // vivods:
      if (ok) {
        mn_iters = min(mn_iters, iters);
        // left
        hg_iters = iters - 1;
      } else {
        // right
        lw_iters = iters + 1;
      }
    }

    cout << mn_iters << endl;

    return 0;
  }

  if (A < B) {

    // Strategy:
    // find mni;
    // t[mni] -= A
    long iters = 0;
    auto cmp = greater<>{};
    make_heap(t.begin(), t.end(), cmp);

    while (1) {
      pop_heap(t.begin(), t.end(), cmp);
      long mn = t.back();

      if (mn < 0) {
        iters += iters_for(t[imax(t)], B);
        break;
      }

      t.pop_back();

      pop_heap(t.begin(), t.end(), cmp);
      long mn2 = t.back();
      t.pop_back();

      long its = min((mn2 - mn) / (B - A) + 1, //
                     max(iters_for(mn2, B), iters_for(mn, A)));

      if (its <= 0) {
        its = 1;
      }

      mn -= its * A;
      mn2 -= its * B;
      for (size_t j = 0; j < t.size(); j++) {
        t[j] -= its * B;
      }

      t.push_back(mn);
      push_heap(t.begin(), t.end(), cmp);

      t.push_back(mn2);
      push_heap(t.begin(), t.end(), cmp);

      iters += its;
    }

    cout << iters << endl;

    return 0;
  }

  return 0;
}
