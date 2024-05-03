// Copyright 2024 semenInRussia

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;
using uset = unordered_set<size_t>;

int main() {
  size_t n = 0;
  cin >> n;
  vector<uset> g(n + 1);

  g[3].insert(1);

  for (size_t i = 0; i < n; i++) {
    cout << g[i].size() << endl;
  }

  return 0;
}
