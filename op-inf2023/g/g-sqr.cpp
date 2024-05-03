// Copyright 2023 semenInRussia

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

#include <climits>

using ll = long long int;
using ull = unsigned long long int;

using namespace std;

inline ull iters_for(ll temp, ull k) {
  if (temp < 0) {
    return 0;
  }

  ull ttemp = 1ULL * temp;

  ull div = ttemp / k;
  ull p = div * k;
  if (p <= ttemp) {
    return div + 1;
  } else {
    return div;
  }
}

int main() {
  size_t n;
  ll A, B;
  cin >> n >> A >> B;

  vector<ull> t;

  for (size_t i = 0; i < n; i++) {
    ll el;
    cin >> el;
    if (el >= 0) {
      t.push_back(el * 1ULL);
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
    ll mx = *max_element(t.begin(), t.end());
    cout << iters_for(mx, B) << endl;

    return 0;
  }

  // ull sumt = accumulate(t.begin(), t.end(), 0);
  // ull lw_iters = (sumt / (A + B * (t.size() - 1))) + 1;

  ull lw_iters = 1;

  ull hg_iters = *max_element(t.begin(), t.end()) * 2;
  ull mn_iters = hg_iters;

  if (A > B) {
    while (lw_iters <= hg_iters) {
      // mid:
      ull iters = (hg_iters - lw_iters) / 2 + lw_iters;

      // check:
      ull min_its = 0;

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
        if (!iters) {
          break;
        }
        hg_iters = iters - 1;
      } else {
        // right
        lw_iters = iters + 1;
      }
    }
  }

  if (A < B) {
    while (lw_iters <= hg_iters) {
      // mid:
      ull iters = (hg_iters - lw_iters) / 2 + lw_iters;

      if (!iters)
        break;

      // check:
      ull max_its = 0;

      for (auto ti : t) {
        ull mn_b = ((ti - A * iters) / (B - A)) + 1;
        if (ti < A * iters) {
          mn_b = 0;
        }

        if (mn_b > iters) {
          // not ok
          max_its = 0;
          break;
        }

        max_its += iters - mn_b;
      }

      bool ok = max_its >= iters;

      // vivods
      if (ok) {
        mn_iters = min(mn_iters, iters);
        // left
        hg_iters = iters - 1;
      } else {
        // right
        lw_iters = iters + 1;
      }
    }
  }

  cout << mn_iters << endl;

  return 0;
}
