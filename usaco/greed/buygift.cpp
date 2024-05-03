// Copyright 2024 semenInRussia

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;
const int inf = 2e9 + 8;

void solve() {
  int n;
  cin >> n;

  vector<pair<int, int>> p(n);
  for (auto &p : p)
    cin >> p.first >> p.second;

  // sort with a_i let's a_i is m1,
  // so in the interval [i+1,n) (indexes in sorted arr) we need always
  // choose b_i, maximum of b_i in this interval is m2, use here
  // suffix maximum for b
  sort(p.begin(), p.end()); // by a_i

  // build suffix maximum for b
  vector<int> s(n + 1, 0); // s[i] - max on [i+1; n)
  for (int i = n - 2; i >= 0; i--)
    s[i] = max(s[i + 1], p[i + 1].second);

  int ans = inf;
  set<int> bs = {-inf, +inf};
  for (int i = 0; i < n - 1; i++) {
    // p[i].first is maximum for a_i, also it cainted m1
    int m1 = p[i].first, m2 = s[i];
    ans = min(ans, abs(m1 - m2));

    // also we can find m2 in previous b magazines, but because in the
    // next magazines we choose only b, so we must find in the
    // previous things a b[i] that is greater (or equal) to m2.
    auto it = bs.lower_bound(max(m2, m1));
    ans = min(ans, abs(m1 - *it));
    if (*prev(it) > m2)
      ans = min(ans, abs(m1 - *prev(it)));

    // also we can find in previous b_i that is more than m2 and
    // closest to m1
    bs.insert(p[i].second);
  }

  // also check for nth (n-1) is m1, in that case we just need to check most
  // closest b_i

  int m1 = p[n - 1].first;
  for (int i = 0; i < n - 1; i++)
    ans = min(ans, abs(m1 - p[i].second));

  cout << ans << endl;
}

int main() {
  int tt;
  cin >> tt;
  while (tt--)
    solve();
}
