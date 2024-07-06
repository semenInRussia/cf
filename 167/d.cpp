/**
 *    author:  tourist
 *    created: 27.06.2024 17:44:42
 **/
#include <iostream>
#include <vector>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  int mx = *max_element(a.begin(), a.end());
  const int inf = int(1e9);
  vector<int> min_loss(mx + 1, inf);
  for (int i = 0; i < n; i++) {
    min_loss[a[i]] = min(min_loss[a[i]], a[i] - b[i]);
  }
  for (int i = 0; i < mx; i++) {
    min_loss[i + 1] = min(min_loss[i + 1], min_loss[i]);
  }
  vector<int> res(mx + 1);
  for (int i = 0; i <= mx; i++) {
    res[i] = (min_loss[i] <= i ? res[i - min_loss[i]] + 1 : 0);
  }
  int64_t ans = 0;
  for (int i = 0; i < m; i++) {
    int c;
    cin >> c;
    if (c > mx) {
      int diff = c - mx;
      int steps = (diff - 1) / min_loss[mx] + 1;
      ans += steps;
      c -= steps * min_loss[mx];
    }
    ans += res[c];
  }
  cout << 2 * ans << '\n';
  return 0;
}
