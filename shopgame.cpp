// Copyright 2024 semenInRussia
// https://codeforces.com/problemset/problem/1969/D
// *1900

#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int maxn = 3e5;
int n, k;
ll a[maxn], b[maxn], id[maxn];

bool by_d(int i, int j) {
  ll d1 = b[i] - a[i], d2 = b[j] - a[j];
  if (d1 != d2)
    return d1 > d2;
  return b[i] < b[j];
}

void solve() {
  cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    cin >> b[i];

  iota(id, id + n, 0);
  sort(id, id + n, by_d);

  priority_queue<ll> q;
  ll ans = 0, sum = 0, sumb = 0;
  // `sumb` is maximum sum of k b_i
  for (int i = 0; i < n; i++) { // i is amount of things Alice take
    int j = id[i];
    sum += b[j] - a[j];
    q.push(-b[j]), sumb += b[j];
    if (q.size() > k)
      sumb -= -q.top(), q.pop();
    if (i >= k)
      ans = max(sum - sumb, ans);
  }

  cout << ans << endl;
}

int main() {
  int tt;
  cin >> tt;
  while (tt--)
    solve();
}
