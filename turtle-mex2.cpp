// semenInRussia 2024
// https://codeforces.com/contest/2003/problem/D2
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> e(n);
  vector<int> v;
  vector<int> a;
  for (int i = 0; i < n; i++) {
    int l;
    cin >> l;
    a.resize(l);
    for (int j = 0; j < l; j++) {
      cin >> a[j];
    }

    // find the best value of i'th array
    sort(a.begin(), a.end());
    int mex = 0;
    while (binary_search(a.begin(), a.end(), mex)) {
      mex++;
    }
    int x, y;
    x = mex;
    mex++;
    while (binary_search(a.begin(), a.end(), mex)) {
      mex++;
    }
    y = mex;
    e[i] = {x, y};
    v.push_back(x);
    v.push_back(y);
  }

  v.push_back(0);
  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());
  int vsz = (int)v.size();
  vector<vector<int>> g(vsz);

  for (auto [x, y] : e) {
    int i = lower_bound(v.begin(), v.end(), x) - v.begin();
    int j = lower_bound(v.begin(), v.end(), y) - v.begin();
    g[i].push_back(j);
  }

  vector<int> f(vsz);
  for (int x = vsz - 1; x >= 0; x--) {
    f[x] = v[x];
    for (int y : g[x]) {
      assert(y > x);
      f[x] = max(f[x], f[y]);
    }
  }

  int op0 = 0;
  assert(v[0] == 0);
  for (int i = 0; i < n; i++) {
    auto [x, y] = e[i];
    int xx = lower_bound(v.begin(), v.end(), x) - v.begin();
    int yy = lower_bound(v.begin(), v.end(), y) - v.begin();
    op0 = max(op0, x);
    if (g[xx].size() > 1) {
      op0 = max(op0, f[xx]);
    }
  }

  ll ans = 1ll * (m + 1) * op0;

  if (op0 <= m) { // better choose start x, instead of 0
    int cnt = m - op0 + 1;
    ans -= 1ll * op0 * cnt;
    ans += 1ll * (op0 + m) * cnt / 2;
  }

  for (int x : v) {
    if (x > m) {
      break;
    }
    if (op0 <= m && x >= op0) {
      ans -= x;
    } else {
      ans -= op0;
    }
    int xx = lower_bound(v.begin(), v.end(), x) - v.begin();
    ans += max(op0, f[xx]);
  }

  cout << ans << '\n';
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}
