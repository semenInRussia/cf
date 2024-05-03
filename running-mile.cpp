// Copyright 2024 semenInRussia

#include <iostream>
#include <numeric>
#include <set>
#include <vector>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> b(n);
  for (auto &x : b)
    cin >> x;

  // b[l] + b[m] + b[r] - (r - l)
  // (b[r] - r) + b[m] + (b[l] + l)

  const int INF = 1e8;
  vector<int> pl(n, -INF), pr(n, -INF);
  for (int i = 0; i < n - 1; i++)
    pl[i + 1] = max(pl[i], b[i] + i);
  for (int i = n - 1; i > 0; i--)
    pr[i - 1] = max(pr[i], b[i] - i);
  int ans = 0;
  for (int m = 1; m < n - 1; m++)
    ans = max(ans, pl[m] + b[m] + pr[m]);
  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
}
