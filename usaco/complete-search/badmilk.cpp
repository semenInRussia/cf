// Copyright 2024 semenInRussia

#include <bits/stdc++.h>
#include <numeric>
using namespace std;

unordered_set<int> intersection(unordered_set<int> &a, unordered_set<int> &b) {
  unordered_set<int> c{};
  for (auto x : a)
    if (b.count(x))
      c.insert(x);
  return c;
}

int main() {
  ifstream cin("badmilk.in");
  ofstream cout("badmilk.out");

  int n, m, d, s;
  cin >> n >> m >> d >> s;

  vector<vector<int>> pers_milks(n);
  vector<vector<int>> drnk(n);
  for (int i = 0; i < d; i++) {
    int p, milk, time;
    cin >> p >> milk >> time;
    pers_milks[p - 1].push_back(milk - 1);
    drnk[p - 1].push_back(time);
  }

  vector<int> cnt_milk(m, 0);
  for (int milk = 0; milk < m; milk++) {
    for (int p = 0; p < n; p++) {
      cnt_milk[milk] +=
          count(pers_milks[p].begin(), pers_milks[p].end(), milk) >= 1;
    }
  }

  vector<int> ill_time(n, -1);
  for (int i = 0; i < s; i++) {
    int p, time;
    cin >> p >> time;
    ill_time[p - 1] = time;
  }

  vector<unordered_set<int>> ill(n);
  for (auto &s : ill)
    s = {};
  for (int p = 0; p < n; p++) {
    int t = ill_time[p];
    if (t == -1)
      continue;
    int sz = pers_milks[p].size();
    for (int i = 0; i < sz; i++)
      if (drnk[p][i] < t)
        ill[p].insert(pers_milks[p][i]);
  }

  // intersection of all ill[i]
  unordered_set<int> bad = {};
  for (int i = 0; i < m; i++) // bad defaults to all milks sorts
    bad.insert(i);
  for (int i = 0; i < n; i++)
    if (!ill[i].empty())
      bad = intersection(ill[i], bad);

  int ans = 0;
  for (auto milk : bad)
    ans = max(cnt_milk[milk], ans);
  cout << ans;
}
