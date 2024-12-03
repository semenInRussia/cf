// Copyright 2023 semenInRussia

// Copyright 2023 semenInRussia

using namespace std;

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

#define max2(a, b) (a) > (b) ? (a) : (b)
#define max3(a, b, c) max2(a, max2(b, c))

#define min2(a, b) ((a) < (b) ? (a) : (b))
#define min3(a, b, c) min(a, min2(b, c))

size_t find(vector<size_t> &a, size_t x);
size_t with_m(vector<size_t> &a, size_t m);
size_t at_day(vector<size_t> &a, size_t day, size_t t, size_t s);
size_t within_day(vector<size_t> &a, size_t day, size_t t, size_t s);
size_t day_of(size_t tsk, size_t t, size_t s);

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  size_t n, t, s;
  cin >> n >> t >> s;

  vector<size_t> a(n);

  for (size_t i = 0; i < n; i++) {
    cin >> a[i];
  }

  size_t d0 = 0;
  if (t > a.back()) {
    d0 = day_of(a.back(), t, s);
  }

  // if (t > a.back()) {
  //   t = day_of(a.back(), t, s);
  // }

  size_t q;
  cin >> q;

  for (size_t j = 0; j < q; j++) {
    size_t tsk, plc;
    cin >> tsk >> plc;

    size_t i = find(a, tsk);
    size_t ii = n - i - 1;

    size_t d = day_of(a[i], t, s);

    size_t mn = min2(d - d0, ii) + 1;

    size_t p_tasks;

    if (d > 0) {
      p_tasks = at_day(a, d - 1, t, s);
      mn = min2(mn, p_tasks + 1);
    }

    size_t d_tasks = at_day(a, d, t, s);

    size_t nday = ii;

    size_t mx = max3(ii + 1,  //
                     d_tasks, //
                     at_day(a, d0 + ii, t, s));

    if (plc >= mn && plc <= mx) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }

#ifdef TEST
    cout << "{ mx = " << mx << " , mn = " << mn << ", el = " << a[i] << '}'
         << endl;
#endif
  }

  return 0;
}

size_t with_m(vector<size_t> &a, size_t m) {
  if (a.front() >= m) {
    return a.size();
  }

  size_t l = 0;
  size_t r = a.size() - 1;

  while (l <= r) {
    size_t mid = (l + r) / 2;

    if (m <= a[mid]) {
      // left
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }

  return a.size() - l;
}

// a - is reversed sorted array
size_t find(vector<size_t> &a, size_t x) {
  size_t l = 0;
  size_t r = a.size() - 1;

  while (1) {
    size_t mid = (l + r) / 2;

    if (a[mid] == x) {
      return mid;
    }

    if (x < a[mid]) {
      // left
      r = mid - 1;
    } else {
      // right
      l = mid + 1;
    }
  }

  return -1;
}

inline size_t at_day(vector<size_t> &a, size_t day, size_t t, size_t s) {
  if (day * s >= t) {
    return a.size();
  }

  return with_m(a, t - day * s);
}

inline size_t within_day(vector<size_t> &a, size_t day, size_t t, size_t s) {
  if (day == 0) {
    return at_day(a, 0, t, s);
  }

  return at_day(a, day, t, s) - at_day(a, day - 1, t, s);
}

inline size_t day_of(size_t tsk, size_t t, size_t s) {
  if (t <= tsk) {
    return 0;
  }

  return (t - tsk - 1) / s + 1;
}
