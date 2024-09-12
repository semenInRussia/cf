// Copyright 2023 semenInRussia

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void tc() {
  size_t n;
  cin >> n;
  vector<int> a(n);

  for (size_t i = 0; i < n; i++) {
    cin >> a[i];
  }

  long int max_sum = 0;
  long int cur_sum = 0;
  bool prev_odd = !(a[0] & 1);

  for (size_t i = 0; i < n; i++) {
    if (prev_odd == (a[i] & 1) || cur_sum < 0) {
      // new subarr
      max_sum = max(max_sum, cur_sum);
      cur_sum = a[i];
      prev_odd = a[i] & 1;
      continue;
    }

    if (a[i] < 0) {
      max_sum = max(max_sum, cur_sum);
    }

    cur_sum += a[i];
    prev_odd = a[i] & 1;
  }

  max_sum = max(max_sum, cur_sum);

  if (0 == max_sum) {
    max_sum = (long int)*max_element(a.begin(), a.end());
  }

  cout << max_sum << endl;
}

int main() {
  size_t t;
  cin >> t;

  while (t--) {
    tc();
  }

  return 0;
}
