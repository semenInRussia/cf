// Copyright 2024 semenInRussia
//
// CF https://codeforces.com/problemset/problem/1965/B
// :not solved

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> answ, ign;
  for (int b = 1; b <= n; b <<= 1) {
    answ.push_back(b);
    if (k & b)
      ign.push_back(-b);
  }

  int b = -ign.back();
  ign.pop_back(), answ.erase(find(answ.begin(), answ.end(), b));

  if (ign.empty()) {
    // if |ign| = 1
    // ans is ign + 2^0, ign + 2^1, ..., ign + 2^n
    vector<int> ad;
    for (int x : answ)
      ad.push_back(x + b);
    for (int x : ad)
      answ.push_back(x);
  } else {
    // if |ign| > 1
    // ans is 2^0, 2^1
    // ++ except 2^k
    // ++ 2^k - 2^s, 2^k - 2^t, ...
    for (int x : ign)
      answ.push_back(x + b);
  }

  cout << answ.size() << '\n';
  for (int x : answ)
    cout << x << ' ';
  cout << endl;
}

int main() {
  int tt;
  cin >> tt;
  while (tt--)
    solve();
}
