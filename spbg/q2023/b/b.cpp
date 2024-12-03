// Copyright 2024 semenInRussia

#include <algorithm>
#include <climits>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

using ll = long long int;

ll max_seg_sum(vector<ll> &arr) {
  ll mx = 0;
  ll seg_sum = 0;

  for (auto x : arr) {
    seg_sum += x;
    if (seg_sum < 0) {
      seg_sum = 0;
    } else {
      mx = max(seg_sum, mx);
    }
  }

  return mx;
}

int main() {
  size_t n;
  cin >> n;

  vector<ll> a(n), b(n);

  for (size_t i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }

  ll mx = *max_element(a.begin(), a.end());

  if (mx <= 0) {
    cout << '0' << endl;

    return 0;
  }

  mx = max(mx, max_seg_sum(a));

  // strategy:
  // - suffix sum for a,
  // - prefix sum for b,
  // - maximums for b,
  //
  // for every i [0,i]: a[i]+mx_b[i]

  vector<ll> tmp(n);

  // suffixes sums
  partial_sum(a.rbegin(), a.rend(), tmp.rbegin());
  copy(tmp.begin(), tmp.end(), a.begin());

  // prefixes sums
  partial_sum(b.begin(), b.end(), tmp.begin());

  // prefix maxs
  partial_sum(tmp.begin(), tmp.end(), b.begin(),
              [](ll a, ll b) { return max(a, b); });

  for (size_t i = 1; i < n; i++) {
    // i is start
    // the sum = a[i] + b[i-1]
    // -3, 2, -3, 2
    ll sum = a[i] + b[i - 1];
    mx = max(sum, mx);
  }

  cout << mx << endl;

  return 0;
}
