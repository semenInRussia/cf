// semenInRussia 2024
// https://codeforces.com/contest/1986/problem/E
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
using pii = pair<int, int>;
const int inf = 1e9;

const int maxn = 2e5;
int a[maxn], p[maxn], r[maxn];
map<int, vector<int>> t;
void solve() {
  int n, k;
  cin >> n >> k;
  t.clear();
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    t[a[i] % k].push_back(a[i]);
  }
  int odds = 0;
  for (auto &[_m, row] : t)
    odds += row.size() & 1;
  if (odds > 1) {
    cout << "-1\n";
    return;
  }
  int ans = 0;
  for (auto &[_m, row] : t) {
    sort(row.begin(), row.end());
    int m = (int)row.size();
    p[0] = 0;
    for (int i = 1; i <= m; i++) {
      p[i] = p[i - 1];
      if (i % 2 == 0)
        p[i] += (row[i - 1] - row[i - 2]) / k;
    }
    if (m == 1)
      ans += 0;
    else if (m % 2 == 0)
      ans += p[m];
    else {
      r[m] = r[m - 1] = 0;
      for (int i = m - 2; i >= 0; i--) {
        r[i] = r[i + 1];
        if ((m - i - 1) % 2 == 0)
          r[i] += (row[i + 2] - row[i + 1]) / k;
      }

      int bst = +inf;
      for (int i = 0; i < m; i++) {
        if (i & 1)
          bst = min(bst, p[i] + r[i] + row[i + 1] - row[i - 1]);
        else
          bst = min(bst, p[i] + r[i]);
      }
      ans += bst;
    }
  }
  cout << ans << '\n';
}

int main() {
  int T;
  cin >> T;
  while (T--)
    solve();
}
