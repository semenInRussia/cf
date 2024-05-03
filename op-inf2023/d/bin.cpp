// Copyright 2023 semenInRussia

using namespace std;

#include <iostream>
#include <vector>

size_t greater_than(vector<size_t> &a, size_t x) {
  if (a.front() >= x) {
    return a.size();
  }

  size_t l = 0;
  size_t r = a.size() - 1;

  while (l <= r) {
    size_t mid = (l + r) / 2;

    if (x <= a[mid]) {
      // left
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }

  return a.size() - l;
}

int main() {
  vector<int> arr = {1, 3, 5, 8};

  size_t x;
  cin >> x;

  cout << ">" << endl << find(arr, x) << endl;
}
