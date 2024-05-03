// Copyright 2023 semenInRussia

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using ll = long long int;

using namespace std;

inline ll iters_for(ll temp, ll k) {
  if (temp < 0) {
    return 0;
  }

  ll div = temp / k;
  ll p = div * k;
  if (p <= temp) {
    return div + 1;
  } else {
    return div;
  }
}

int main() {
  size_t n;
  ll A, B;
  cin >> n >> A >> B;

  vector<ll> t;

  for (size_t i = 0; i < n; i++) {
    ll el;
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
    ll mx = *max_element(t.begin(), t.end());
    cout << iters_for(mx, B) << endl;

    return 0;
  }

  ll sumt = accumulate(t.begin(), t.end(), 0);
  ll lw_iters = sumt / (A + B * (t.size() - 1)) + 1;

  if (A > B) {
    ll hg_iters = iters_for(*max_element(t.begin(), t.end()), B);
    ll mn_iters = hg_iters;

    while (lw_iters <= hg_iters) {
      // mid:
      ll iters = (lw_iters + hg_iters) / 2;

      // check:
      ll min_its = 0;

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
    ll hg_iters = iters_for(*max_element(t.begin(), t.end()), A);
    ll mn_iters = hg_iters;

    while (lw_iters <= hg_iters) {
      // mid:
      ll iters = (lw_iters + hg_iters) / 2;

      // check:
      ll min_its = 0;

      for (auto ti : t) {
        ll mn_b = ((ti - A * iters) / (B - A)) + 1;
        if (ti < A * iters) {
          mn_b = 0;
        }

        if (mn_b > iters) {
          // not ok
          min_its = iters * t.size();
          break;
        }

        min_its += mn_b;
      }

      bool ok = min_its <= (iters * (t.size() - 1));

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

    cout << mn_iters << endl;
  }
}
