// semenInRussia 2024
// https://codeforces.com/problemset/problem/1978/d
#include <algorithm>
#include <iostream>
// #include <set>
#include <map>
using namespace std;
const int N = 2e5, inf = 1e9;
using pii = pair<int, int>;
using ll = long long;
int a[N], _a[N], ans[N];
ll p[N], s[N];
int rmx[N], cnt[N];
void solve() {
  int n;
  ll c;
  cin >> n >> c;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  copy(a, a + n, _a);
  sort(_a, _a + n);
  fill(ans, ans + n, -1);

  s[n] = s[n - 1] = 0;
  for (int i = n - 1; i - 1 >= 0; i--)
    s[i - 1] = s[i] + _a[i];

  p[0] = c;
  for (int i = 0; i < n; i++)
    p[i + 1] = p[i] + a[i];

  rmx[n - 1] = -inf;
  for (int i = n - 1; i - 1 >= 0; i--)
    rmx[i - 1] = max(a[i], rmx[i]);

  // cnt[i] - is time when a[i] was occurred in array before
  map<int, int> cc;
  for (int i = 0; i < n; i++)
    cnt[i] = cc[a[i]]++;

  for (int i = 0; i < n; i++) {
    // two options:
    //
    // 1. remove maximums, but add them to the C
    ans[i] = +inf;
    if (i && a[i] > a[0] + c) {
      int l = lower_bound(_a, _a + n, a[i]) - _a;
      // 3 3 3 3
      //   ^
      //   1
      l += cc[a[i]] - cnt[i] - 1;
      if (c + 1ll * a[0] + s[l] < a[i])
        ans[i] = n - l - 1;
    }
    // 2. remove before i, remove maximums and add them to the ai
    ans[i] = min(ans[i], i + (p[i + 1] < ll(rmx[i])));
  }

  for (int i = 0; i < n; i++)
    cout << ans[i] << ' ';
  cout << '\n';
}

int main() {
  int T;
  cin >> T;
  while (T--)
    solve();
}
