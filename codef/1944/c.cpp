// Copyright 2024 semenInRussia

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// if zero 0
// if one 1 --- 1

void solve() {
  int n;
  cin >> n;

  vector<int> cnt(n + 2, 0);

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    cnt[x]++;
  }

  // if count i == 1.
  // and that lower are 2, then Alice can choose it firstly

  // A. check cnt[i] == 0
  int found = 0;
  for (int i = 0; i <= n; i++) {
    found += cnt[i] == 1;

    if (cnt[i] == 0 || found == 2) {
      cout << i << '\n';
      return;
    }
  }
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();

  return 0;
}
