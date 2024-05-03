// Copyright 2024 semenInRussia

#include <algorithm>
#include <fstream>
#include <numeric>
#include <vector>

using namespace std;

void operator>>(ifstream &in, vector<int> &a) {
  for (auto &x : a)
    in >> x;
}

int main() {
  ifstream cin("diamond.in");
  ofstream cout("diamond.out");

  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  cin >> a;

  sort(a.begin(), a.end());
  vector<int> s(n + 1), p(n + 1);

  int l = 0, r = 0;
  while (l < n) { // for every L, find max R
    while (r + 1 < n && a[r + 1] - a[l] <= k)
      r++;
    s[l] = r - l + 1;
    l++;
  }
  // for every i, find the maximum array len with L and R >= i
  for (int i = n - 1; i >= 0; i--)
    s[i] = max(s[i + 1], s[i]);

  l = n - 1, r = n - 1;
  while (r >= 0) { // for every R, find minimum L
    while (l - 1 >= 0 && a[r] - a[l - 1] <= k)
      l--;
    p[r + 1] = max(p[r], r - l + 1); // p[i] is max answer with R, L < i
    r--;
  }

  int ans = -1;
  for (int i = 0; i <= n; i++)
    ans = max(ans, s[i] + p[i]);
  cout << ans;
}
