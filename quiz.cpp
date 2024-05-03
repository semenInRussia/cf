// Copyright 2024 semenInRussia

// 1 5 7 6 4 3 5 7

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int maxn = 1e5 + 100, inf = maxn + 100;

vector<vector<int>> factors;

void setup() {
  factors.resize(maxn);
  for (int x = 1; x < maxn; x++)
    for (int m = x; m < maxn; m += x)
      factors[m].push_back(x);
}

void display(vector<int> &xs) {
  for (auto x : xs)
    cout << x << ' ';
  cout << '\n';
}

void rem(int &cnt, vector<int> &freq, int x) {
  vector<int> fs = factors[x];
  int m = (int)freq.size();
  for (auto f : fs)
    if (f < m)
      cnt += --freq[f] == 0;
    else
      break;
}

void add(int &cnt, vector<int> &freq, int x) {
  vector<int> fs = factors[x];
  int m = (int)freq.size();
  for (auto f : fs)
    if (f < m)
      cnt += (++freq[f]) == 1;
    else
      break;
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (auto &x : a)
    cin >> x;

  sort(a.begin(), a.end());

  vector<int> freq(m + 1, 0);
  int cnt = 0, l = 0, r = 0, ans = inf;
  bool ok = false;

  while (l < n) {
    // check right bound for every l
    while (cnt != m && r < n)
      add(cnt, freq, a[r++]);

    // save answer if correct interval
    ok |= cnt == m;
    if (cnt == m)
      ans = min(ans, a[r - 1] - a[l]);

    // move left bound
    rem(cnt, freq, a[l++]);
  }

  cout << (ok ? ans : -1) << endl;
}

int main() {
  setup();
  int tt;
  cin >> tt;
  while (tt--)
    solve();
}
