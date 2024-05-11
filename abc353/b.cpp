// Copyright 2024 semenInRussia

#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
const int mod = 1e8;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  int free = k, ans = 1;
  for (int i = 0; i < n; i++) {
    if (free >= a[i])
      free -= a[i];
    else
      ans += 1, free = k - a[i];
  }

  cout << ans << '\n';
}
