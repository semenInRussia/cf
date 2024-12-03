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

  vector<size_t> mx(n);
  vector<size_t> mn(n);

  // a[-1] < t
  // a[-1] > t - i*s
  // i*s = t - a[-1]
  size_t d0 = day_of(a.back(), t, s);
  t -= d0 * s;

  mx[n - 1] = within_day(a, 0, t, s) - 1;
  mn[n - 1] = 0;

  mn.emplace_back(1, 2);

  size_t pmn_day = 0;
  size_t mx_day = 1;

  for (size_t j = a.size() - 1; j > 0; j--) {
    size_t i = j - 1;

    size_t mn_day = day_of(a[i], t, s);
    size_t bdays = mn_day - pmn_day;

    if (bdays == 0) {
      mn[i] = mn[i + 1];
    } else {
      size_t wday = at_day(a, pmn_day, t, s) - mn[i + 1];
      mn[i] = mn[i + 1] + min2(wday, bdays);
    }

    mx_day = max(mx_day, mn_day);
    mx[i] = at_day(a, mx_day, t, s) - 1;

    // at the end of iter:
    mx_day++;
    pmn_day = mn_day;
  }

#ifdef TEST
  cout << "mn = { ";
  for (auto mni : mn) {
    cout << mni << ' ';
  }
  cout << "}" << endl;

  cout << "mx = { ";
  for (auto mxi : mx) {
    cout << mxi << ' ';
  }
  cout << "}" << endl;
#endif

  size_t q;
  cin >> q;

  while (q--) {
    size_t tsk, plc;
    cin >> tsk >> plc;
    plc--;

    size_t i = find(a, tsk);

    if (plc >= mn[i] && plc <= mx[i]) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
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
