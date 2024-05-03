// Copyright 2024 semenInRussia

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

const int maxn = 2e5;
int n, k, a[maxn], f[maxn + 1];

bool check(int x) {
  for (int i = 0; i < n; i++)
    f[i + 1] = f[i] + (a[i] >= x ? +1 : -1);

  int ans = false, mn = f[0];
  for (int j = k; j <= n; j++) {
    mn = min(mn, f[j - k]);
    if (f[j] > mn)
      ans = true;
  }
  return ans;
}

int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  int l = 1, r = n + 1;
  while (r > l + 1) {
    int mid = (r + l) / 2;
    if (check(mid))
      l = mid;
    else
      r = mid;
  }

  cout << l << '\n';
}
