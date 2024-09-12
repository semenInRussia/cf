// semenInRussia 2024
// https://codeforces.com/contest/2003/problem/D1
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n);
  for (int i = 0; i < n; i++) {
    int l;
    cin >> l;
    a[i].resize(l);
    for (int j = 0; j < l; j++) {
      cin >> a[i][j];
    }
  }

  int best = 0;
  for (int i = 0; i < n; i++) {
    // find the best value of i'th array
    sort(a[i].begin(), a[i].end());
    int mex = 0;
    while (binary_search(a[i].begin(), a[i].end(), mex)) {
      mex++;
    }
    mex++;
    while (binary_search(a[i].begin(), a[i].end(), mex)) {
      mex++;
    }
    best = max(mex, best);
  }

  if (best >= m) {
    cout << 1ll * best * (m + 1) << '\n';
  } else {
    cout << 1ll * best * best + 1ll * (best + m) * (m - best + 1) / 2 << '\n';
  }
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}
