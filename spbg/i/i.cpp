// Copyright 2024 semenInRussia

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

#define q(i) (data.query(i))

int main() {
  size_t n, k;
  cin >> n >> k;

  vector<size_t> elems(k);

  for (auto &el : elems) {
    cin >> el;
  }

  for (size_t i = 0; i < n; i++) {
    cout.flush();
    cout << i + 1 << endl;
    size_t x;
    cin >> x;
  }

  cout << '0' << endl;

  return 0;
};
