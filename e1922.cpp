// Copyright 2024 semenInRussia

#include <iterator>
#include <numeric>
using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>

vector<size_t> sums = {0};

void gen(size_t x) {
  if (sums.back() > x)
    return;

  while (sums.back() <= x) {
    sums.push_back(sums.back() + sums.size());
  }
}

vector<size_t> ans;

void solve(size_t x) {
  gen(x);

  auto it = lower_bound(sums.begin(), sums.end(), x) - 1;
  size_t c = *it;

  size_t sz = distance(sums.begin(), it);

  for (size_t i = 0; i < sz; i++) {
    ans.push_back(i);
  }

  if (c == x)
    return;

  ans.push_back(0);
  c++;

  if (c == x)
    return;

  solve(x - c);
}

int main() {
  size_t t;
  cin >> t;

  while (t--) {
    size_t x;
    cin >> x;

    solve(x);
    cout << ans.size() << endl;

    for (auto x : ans) {
      cout << x << ' ';
    }
    cout << endl;

    ans.clear();
  }

  return 0;
}
