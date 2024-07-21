// semenInRussia 2024
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int N = 1e6;
int a[N], _a[N], b[N], _b[N];
int p[N];
void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    char ch;
    cin >> ch;
    a[i] = _a[i] = ch - '0';
  }
  for (int i = 0; i < n; i++) {
    char ch;
    cin >> ch;
    b[i] = _b[i] = ch - '0';
  }
  for (int i = 0; i + 2 < n; i++)
    if (a[i] == 0 && a[i + 2] == 0)
      _b[i + 1] = 1;
  for (int i = 0; i + 2 < n; i++)
    if (_b[i] == 1 && _b[i + 2] == 1)
      _a[i + 1] = 1;
  for (int i = 0; i < n; i++)
    p[i + 1] = p[i] + _a[i];

  // handle queries
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    if (1 + r - l <= 3) {
      vector<int> a2(a + l, a + r + 1), b2(b + l, b + r + 1);
      int n = (int)a2.size();
      for (int i = 0; i + 2 < n; i++)
        if (a2[i] == 0 && a2[i + 2] == 0)
          b2[i + 1] = 1;
      for (int i = 0; i + 2 < n; i++)
        if (b2[i] == 1 && b2[i + 2] == 1)
          a2[i + 1] = 1;
      cout << count(a2.begin(), a2.end(), 1) << '\n';
      continue;
    }
    int ans = p[r + 1] - p[l];
    if (a[l] == 0 && _a[l] == 1)
      ans--;
    if (l + 1 < n && b[l] == 0 && _b[l] != b[l] && a[l + 1] == 0 &&
        a[l + 1] != _a[l + 1])
      ans--;
    if (a[r] == 0 && _a[r] != a[r])
      ans--;
    if (b[r] == 0 && _b[r] != b[r] && r - 1 >= 0 && a[r - 1] == 0 &&
        a[r - 1] != _a[r - 1])
      ans--;
    cout << ans << '\n';
  }
}
int main() {
  int T;
  cin >> T;
  while (T--)
    solve();
}
