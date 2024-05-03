// Copyright 2023 semenInRussia

#include <numeric>
using namespace std;

#include <iostream>
#include <vector>

#define day(t) ((t - k) / m)

int main() {
  size_t n;
  int m;
  cin >> n >> m;

  vector<int> t(n);

  for (size_t i = 0; i < n; i++) {
    cin >> t[i];
  }

  int k = 0;

  while (k < m) {
    // check day from i to n-2,
    // d[i+1] - d[i]
    //
    // d[i] = (t[i] - k) / m
    bool ok = true;
    int dist;
    size_t i = 0;

    for (; i < n - 1; i++) {
      dist = day(t[i + 1]) - day(t[i]);

      if (dist < 0 || dist > 1) {
        ok = false;
        break;
      }
    }

    if (ok) {
      cout << k << endl;
      return 0;
    }

    if (dist > 2) {
      // noooo
      // exit with -1
      break;
    }

    // next k to decrease the day at i + 1
    int next_k = t[i + 1] % m + 1;

    if (next_k <= k) {
      break;
    }

    k = next_k;
  }

  cout << "-1" << endl;

  return 0;
}
