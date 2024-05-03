// Copyright 2024 semenInRussia

#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (auto &x : a)
    cin >> x;

  vector<int> p(n), s(n);
  auto f = [](int a, int b) { return gcd(a, b); };
  partial_sum(a.begin(), a.end(), p.begin(), f);
  partial_sum(a.rbegin(), a.rend(), s.rbegin(), f);

  int ans = max(s[1], p[n - 2]); // otherwise cases handle in `for`
  for (int i = 1; i < n - 1; i++)
    ans = max(ans, gcd(p[i - 1], s[i + 1]));
  cout << ans << endl;
}
