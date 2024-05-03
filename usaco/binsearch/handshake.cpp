// Copyright 2024 semenInRussia

#include <bitset>
#pragma GCC optimize("O3,unroll-loops")

#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
const int maxn = 1e5;
int n, m, a[maxn];

bitset<maxn> seen;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a, a + n), reverse(a, a + n);

  priority_queue<pair<int, pii>> q;
  for (int i = 0; i < n; i++)
    q.push({a[0] + a[i], {i, 0}});

  ll ans = 0;
  while (m--) {
    auto top = q.top();
    q.pop();
    ans += top.first;
    int i = top.second.first, j = top.second.second;
    j++;
    if (j == n)
      continue;
    if (i != j || !seen[i])
      q.push({a[i] + a[j], {i, j}}), seen[i] = seen[i] || i == j;
  }

  cout << ans << endl;
}
