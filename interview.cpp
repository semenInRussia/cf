// semenInRussia 2024
// https://codeforces.com/problemset/problem/1976/C
#include <cassert>
#include <iostream>
using namespace std;

const int N = 2e5 + 100;
int a[N], b[N], typ[N];
using ll = long long;
ll ans[N];

ll naive(int n, int m) {
  ll A = 0, B = 0;
  int ak = 0, bk = 0;
  for (int i = 0; i < n + m; i++) {
    if (bk >= m || (ak < n && a[i] > b[i]))
      ak++, A += a[i];
    else
      bk++, B += b[i];
  }
  return A + B;
}

void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n + m + 1; i++)
    cin >> a[i];
  for (int i = 0; i < n + m + 1; i++)
    cin >> b[i];

  ll A = 0, B = 0;
  int ak = 0, bk = 0;
  for (int i = 0; i < n + m; i++) {
    if (bk >= m || (ak < n && a[i] > b[i]))
      ak++, A += a[i], typ[i] = 0;
    else
      bk++, B += b[i], typ[i] = 1;
  }
  ans[n + m] = A + B;

  ll x[2] = {naive(n + 1, m), naive(n, m + 1)};
  int *rs[2];
  rs[0] = a, rs[1] = b;
  for (int i = 0; i < n + m; i++)
    ans[i] = x[typ[i]] - rs[typ[i]][i];
  for (int i = 0; i < n + m + 1; i++)
    cout << ans[i] << " \n"[i == n + m];
}

int main() {
  int T;
  cin >> T;
  while (T--)
    solve();
}
