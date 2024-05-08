// Copyright 2024 semenInRussia
// CF https://codeforces.com/problemset/problem/1956/D
// #constructive *2000

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
using pii = pair<ll, ll>;
ll a[19];

// fill segment from start to start+i with i
void f(vector<pii> &path, int i, int start, bool first = false) {
  if (i == 0)
    return;
  if (i == 1) {
    path.push_back({start, start});
    return;
  }

  for (int j = i - 1, b = start; j >= 0; j--, b++)
    f(path, j, b);
  path.push_back({start, start + i - 1});
  if (!first)
    path.push_back({start + 1, start + i - 1});
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  pii ans = {0, 0}; // first is sum, second is bit-mask

  for (int b = 0; b < (1 << n); b++) {
    ll s = 0, k = 0; // sum and length of segment
    for (int i = 0; i < n; i++) {
      if ((b >> i) & 1) { // not change a[i]
        s += a[i], s += k * k;
        k = 0;
      } else
        // change this element, segment can be updated to k^2 (k -
        // length)
        k++;
    }
    s += k * k;
    ans = max(ans, {s, b});
  }

  auto [s, b] = ans;

  vector<pii> segments;
  int l = -1;
  for (int i = 0; i < n; i++) {
    int bit = (b >> i) & 1;
    if (bit) {
      if (l != -1)
        segments.push_back({l, i - 1});
      l = -1;
    } else if (l == -1)
      l = i;
  }

  if (l != -1)
    segments.push_back({l, n - 1});

  vector<pii> path;
  for (auto segm : segments) {
    auto [l, r] = segm;
    if (count(a + l, a + r + 1, 0) > 0)
      path.push_back(segm);
    path.push_back(segm);
    f(path, segm.second - segm.first + 1, segm.first, true);
  }

  cout << s << ' ' << path.size() << '\n';
  for (auto [l, r] : path)
    cout << (l + 1) << ' ' << (r + 1) << '\n';
}
