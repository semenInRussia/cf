// Copyright 2023 semenInRussia

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

using uint = unsigned int;

int main() {
  size_t t;
  cin >> t;

  while (t--) {
    size_t n;
    cin >> n;

    vector<uint> a(2 * n);

    for (size_t i = 0; i < 2 * n; i++) {
      cin >> a[i];
    }

    sort(a.begin(), a.end());

    size_t s = 0;

    for (size_t i = 1; i < n; i++) {
      s += a[i] - a[i - 1];
    }

    for (size_t i = 1; i < n; i++) {
      s += a[n + i] - a[n + i - 1];
    }

    cout << s << endl;

    for (size_t i = 0; i < n; i++) {
      cout << a[n + i] << ' ' << a[i] << endl;
    }
  }

  return 0;
}
