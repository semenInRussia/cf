// Copyright 2024 semenInRussia
#include <iostream>
#include <vector>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> b(n);
  for (auto &x : b)
    cin >> x;

  const int INF = 1e8;
  vector<int> p(n, -INF), s(n, -INF);
  for (int i = 0; i < n - 1; i++)
    p[i + 1] = max(p[i], b[i] + i);
  for (int i = n - 1; i > 0; i--)
    s[i - 1] = max(s[i], b[i] - i);
  int ans = -1;
  for (int m = 1; m < n - 1; m++)
    ans = max(ans, p[m] + b[m] + s[m]);
  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
}
