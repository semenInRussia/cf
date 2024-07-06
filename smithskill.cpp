// semenInRussia 2024
// https://codeforces.com/problemset/problem/1989/D
#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;
const int inf = 1e9;

const int maxn = 3e6;
int a[maxn], b[maxn];
ll c[maxn];
int best[maxn];
ll ans[maxn];
int main() {
  ios::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  ll A = -1;
  for (int i = 0; i < n; i++)
    cin >> a[i], A = max(A, 1ll * a[i]);
  for (int i = 0; i < n; i++)
    cin >> b[i];
  for (int i = 0; i < m; i++)
    cin >> c[i];
  fill(best, best + A + 1, +inf);
  for (int i = 0; i < n; i++)
    best[a[i]] = min(best[a[i]], a[i] - b[i]);
  for (int i = 1; i <= A; i++)
    best[i] = min(best[i - 1], best[i]);

  // ans[i] = score for x=i
  for (int i = 0; i <= A; i++)
    if (i >= best[i])
      ans[i] = 2ll + ans[i - best[i]];
  ll res = 0;
  for (int i = 0; i < m; i++) {
    if (c[i] <= A)
      res += ans[c[i]];
    else {
      ll d = best[A];
      ll k = (c[i] - A + d - 1) / d;
      res += ans[c[i] - k * d] + k * 2;
    }
  }
  cout << res;
}
