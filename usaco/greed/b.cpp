// Copyright 2024 semenInRussia

#include <algorithm>
#include <iostream>
#include <vector>

using ll = long long;
using namespace std;

const int maxn = 2e5;
int f[maxn], p[maxn], t[maxn], n, k, d[maxn];

ll cost(int pos) {
  ll sm = 0;
  for (int i = 0; i < k; i++)
    sm += ((abs(pos - p[i])) <= d[i]) * t[i];
  return sm;
}

int main() {
  int k, m, n;
  cin >> k >> m >> n;
  for (int i = 0; i < k; i++)
    cin >> p[i] >> t[i];
  for (int i = 0; i < m; i++)
    cin >> f[i];
  for (int i = 0; i < m; i++)
    f[i] *= 2;
  for (int i = 0; i < k; i++)
    p[i] *= 2;

  // find d[i]
  sort(f, f + m);
  for (int i = 0; i < k; i++) {
    auto it = lower_bound(f, f + m, p[i]);
    // it >= p[i]
    if (it == (f + m))
      d[i] = abs(p[i] - f[m - 1]);
    else if (it == f)
      d[i] = *it - p[i];
    else
      d[i] = min(p[i] - *prev(it), *it - p[i]);
  }

  vector<int> vars;
  for (int i = 0; i < k; i++) {
    vars.push_back(p[i] - d[i] + 1);
    vars.push_back(p[i] + d[i] - 1);
  }

  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ll mxsum = 0;
    int mxpos = 0;
    for (auto pos : vars) {
      ll cur = cost(pos);
      if (cur >= mxsum)
        mxpos = pos, mxsum = cur;
    }
    ans += mxsum;
    for (int i = 0; i < k; i++)
      if (abs(p[i] - mxpos) <= d[i])
        d[i] = 0;
  }

  cout << ans << endl;
}
