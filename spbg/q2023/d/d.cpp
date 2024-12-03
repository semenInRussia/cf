// Copyright 2024 semenInRussia

#include <iterator>
using namespace std;

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using Set = set<size_t>;
using Diff = pair<size_t, size_t>;

template <typename T> pair<T, T> sort_pair(pair<T, T> p) {
  if (p.first <= p.second)
    return p;
  return {p.second, p.first};
}

int main() {
  size_t a, b, c;
  cin >> a >> b >> c;

  if (a < b)
    swap(a, b);

  const size_t n = max(a, c) * 2;

  vector<Set> equals(n);
  vector<Set> different(n);

  for (size_t i = 0; i < n; i++) {
    equals[i].insert(i);

    // % b : 0 1 2  | 0 1 2
    // % a : 0 1 2  | 3 4 5
    // % c : 0 1 0  | 1 0 1
    equals[i % b].insert(i % a);
    equals[i % a].insert(i % b);

    different[i % c].insert(i % a);
    different[i % c].insert(i % b);

    different[i % b].insert(i % c);
    different[i % a].insert(i % c);
  }

  set<Diff> diffs;

  for (size_t i = 0; i < n; i++) {
    auto eq = equals[i];
    auto df = different[i];

    for (auto x : df) {
      if (!eq.count(x)) {
        diffs.insert(sort_pair<size_t>({*eq.begin(), x}));
        break;
      }
    }
  }

  for (auto d : diffs) {
    cout << "{ " << d.first << " " << d.second << "} " << endl;
  }

  cout << diffs.size() << endl;

  return 0;
}
