// Copyright 2024 semenInRussia

#include <iostream>

using namespace std;
using ll = long long;
const int inf = 1e9;

int main() {
  int n, k;
  cin >> n >> k;

  int ans = inf;
  for (int a = 1; a < n; a++) {
    int cur = (2 * a + k - 2) * (k - 1);
    int s = n - cur;
    if (s > a + k - 2 || (s > 0 && s < a))
      ans = min(ans, s - a);
  }

  cout << (ans == inf ? -1 : ans) << endl;
}
