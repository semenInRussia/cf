// Copyright 2024 semenInRussia

// cf:
// https://codeforces.com/problemset/problem/1624/D

#include <iostream>
using namespace std;

void solve() {
  int n, k;
  string s;
  cin >> n >> k >> s;

  int cnt[26];
  fill(cnt, cnt + 26, 0);
  for (auto ch : s)
    cnt[ch - 'a']++;

  int p = 0, extra = 0;
  for (auto c : cnt)
    extra += c % 2, p += c / 2;

  int pairs = 2 * (p / k);
  int can_middle = (2 * p - pairs * k) + extra >= k;
  cout << (pairs + can_middle) << '\n';
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
}
