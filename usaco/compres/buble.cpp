// Copyright 2024 semenInRussia
#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int main() {
  ifstream cin("sort.in");
  ofstream cout("sort.out");

  int n;
  cin >> n;
  vector<pii> a(n);
  int i = 0;
  for (auto &x : a) {
    cin >> x.first;
    x.second = i++;
  }

  sort(a.begin(), a.end());
  i = 0;
  for (auto &x : a)
    x.first = i++;

  int ans = 0;
  for (auto x : a)
    ans = max(ans, (x.second - x.first));
  cout << (ans + 1);
}
