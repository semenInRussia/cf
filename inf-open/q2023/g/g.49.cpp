// Copyright 2023 semenInRussia

#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

inline long iters_for(long temp, long k) {
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

  if (A > B) {
    auto cmp = less<>{};
    long iters = 0;
    make_heap(t.begin(), t.end(), cmp);

    while (1) {
      pop_heap(t.begin(), t.end(), cmp);
      long mx = t.back();
      t.pop_back();

      if (mx < 0) {
        break;
      }

      pop_heap(t.begin(), t.end(), cmp);
      long mx2 = t.back();
      t.pop_back();

      long its = min((mx - mx2) / (A - B) + 1, //
                     max(iters_for(mx, A), iters_for(mx2, B)));

      mx -= its * A;
      mx2 -= its * B;

      for (size_t j = 0; j < t.size(); j++) {
        t[j] -= its * B;
      }

      t.push_back(mx);
      push_heap(t.begin(), t.end(), cmp);

      t.push_back(mx2);
      push_heap(t.begin(), t.end(), cmp);

      iters += its;
    }

    cout << iters << endl;

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
}
