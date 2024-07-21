// semenInRussia 2024
// https://codeforces.com/problemset/problem/1984/D
#include <algorithm>
using namespace std;
#include <iostream>
using ll = long long;
const int maxn = 2e5 + 100;
int z[maxn], nxt[maxn];
void solve() {
  string s;
  cin >> s;
  int n = int(s.size());
  if (count(s.begin(), s.end(), 'a') == n) {
    cout << n - 1 << '\n';
    return;
  }
  // chop all "a" from the left
  reverse(s.begin(), s.end());
  while (s.back() == 'a')
    s.pop_back();
  reverse(s.begin(), s.end());
  int as = n - int(s.size());
  n = int(s.size());
  int l = 0, r = 1;
  z[0] = 0;
  for (int i = 1; i < n; i++) {
    z[i] = 0;
    if (i >= l && i < r)
      z[i] = min(r - i, z[i - l]);
    while (i + z[i] < n && s[z[i]] == s[i + z[i]])
      z[i]++;
    if (i + z[i] > r)
      l = i, r = i + z[i];
  }
  int cur = n;
  for (int i = n - 1; i >= 0; i--) {
    nxt[i] = cur;
    if (s[i] != 'a')
      cur = i;
  }

  ll ans = 0;
  for (int i = 0; i < n; i++) {
    int len = i + 1;
    int mn = as, bt = 0;
    int ok = true;
    for (int j = len; j < n && ok;) {
      if (s[j] == 'a')
        bt += nxt[j] - j, j = nxt[j];
      else if (z[j] >= len)
        j += len, mn = min(bt, mn), bt = 0;
      else
        ok = false;
    }
    ans += (mn + 1) * ok;
  }
  cout << ans << '\n';
}

int main() {
  int T;
  cin >> T;
  while (T--)
    solve();
}
