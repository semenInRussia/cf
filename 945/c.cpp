// Copyright 2024 semenInRussia
#include <iostream>
#include <set>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int maxn = 1e5 + 100;
int p[maxn], q[maxn];

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> p[i];

  set<pii> t;
  set<int> r;
  for (int i = 1; i < n - 1; i++)
    t.insert({p[i], i});
  for (int i = 1; i <= n; i++)
    r.insert(i);

  vector<bool> taked(n, 0);
  vector<int> q(n, 0);
  while (!t.empty()) {
    int i = t.rbegin()->second, pi = t.rbegin()->first;
    t.erase(*t.rbegin());
    if (taked[i - 1] || taked[i + 1])
      continue;

    taked[i] = 1;
    int mx = *r.rbegin();
    r.erase(*r.rbegin());
    int mn1, mn2;
    if (!q[i - 1])
      mn1 = *r.begin(), r.erase(*r.begin());
    else
      mn1 = q[i - 1];

    if (q[i + 1])
      mn2 = q[i + 1];
    else
      mn2 = *r.begin(), r.erase(*r.begin());

    q[i - 1] = mn1, q[i + 1] = mn2;
    q[i] = mx;
  }

  for (int i = 0; i < n; i++) {
    if (!q[i])
      q[i] = *r.begin(), r.erase(*r.begin());
  }

  for (auto x : q)
    cout << x << ' ';
  cout << '\n';
}

int main() {
  int tt;
  cin >> tt;
  while (tt--)
    solve();
}
