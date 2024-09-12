// Copyright 2024 semenInRussia

#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

using mset = unordered_multiset<int>;

void solve() {
  int n, k;
  cin >> n >> k;
  mset L(n), R(n);

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    L.insert(x);
  }

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    R.insert(x);
  }

  vector<int> l;
  vector<int> r;

  for (int i = 0; i < n; i++) {
    if (R.count(i) && L.count(i)) {
      l.push_back(i);
    }
  }
}

int main() {
  size_t t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
