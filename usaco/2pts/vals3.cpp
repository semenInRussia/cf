// Copyright 2024 semenInRussia

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

using pii = pair<int, int>;

int main() {
  int n, x;
  cin >> n >> x;

  vector<pii> orig(n);
  int i = 1;
  for (auto &x : orig) {
    cin >> x.first;
    x.second = i++;
  }

  sort(orig.begin(), orig.end());
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    a[i] = orig[i].first;

  int l, r, k;
  for (k = 0; k + 2 < n; k++) {
    l = k + 1;
    r = n - 1;
    while (l < n && r > k + 1 && l < r) {
      int num = a[k] + a[l] + a[r];
      if (num > x)
        r--;
      else if (num < x)
        l++;
      else {
        for (int i : {l, r, k})
          cout << (orig[i].second) << ' ';
        return 0;
      }
    }
  }

  cout << "IMPOSSIBLE";
}
