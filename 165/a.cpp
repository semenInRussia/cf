// Copyright 2024 semenInRussia

#include <iostream>
#include <set>
#include <vector>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using ull = unsigned long long;
const int inf = 1e9;

void solve() {
  int n;
  cin >> n;
  set<pii> m;
  int i = 1;
  for (int z = 0; z < n; z++) {
    int x;
    cin >> x;
    if (m.count({x, i}) || m.count({i, x})) {
      cout << "2\n";
      return;
    }
    m.insert({x, i});
    m.insert({i, x});
    i++;
  }

  cout << "3\n";
}

int main() {
  int tt;
  cin >> tt;
  while (tt--)
    solve();
}
