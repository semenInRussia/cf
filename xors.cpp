// Copyright 2024 semenInRussia
// https://codeforces.com/problemset/problem/1968/F
// #constructive #bits *1800
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> b(n + 1, 0);
  for (int i = 0; i < n; i++) {
    int ai;
    cin >> ai;
    b[i + 1] = ai ^ b[i];
  }
  map<int, set<int>> m;
  for (int i = 0; i <= n; i++)
    m[b[i]].insert(i);

  for (int z = 0; z < q; z++) {
    int l, r;
    cin >> l >> r;
    if (b[l - 1] == b[r]) {
      cout << "YES\n";
      continue;
    }

    bool ans = true;
    int bl = b[l - 1], br = b[r];
    auto s = m[bl].lower_bound(r);
    ans &= s != m[bl].begin();
    s--;

    auto t = m[br].lower_bound(l);
    ans &= t != m[br].end();

    if (ans && *s > *t)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}

int main() {
  int tt;
  cin >> tt;
  while (tt--)
    solve(), cout << "\n";
}
