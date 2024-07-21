// semenInRussia 2024
// https://codeforces.com/problemset/problem/1974/F
#include <algorithm>
#include <iostream>
using namespace std;

const int N = 2e5;
struct point {
  int v;
  int i;
  point(int v = 0) : v(v) {}
};
bool operator<(point a, point b) { return a.v < b.v; }
point xs[N], ys[N];
bool used[N + 100];

void solve() {
  int a, b, n, m;
  cin >> a >> b >> n >> m;
  swap(a, b);
  for (int i = 0; i < n; i++) {
    cin >> ys[i].v >> xs[i].v;
    xs[i].i = ys[i].i = i;
  }
  sort(xs, xs + n), sort(ys, ys + n);
  fill(used, used + n + 2, false);

  int xl = 1, xr = a;
  int yl = 1, yr = b;
  int ans[2]{0, 0};
  int p = 0;

  // 1 2 3 4
  while (m--) {
    char ch;
    int k;
    cin >> ch >> k;
    if (ch == 'U') {
      // add all points >= yl, <= yl + k
      int j0 = lower_bound(ys, ys + n, point(yl)) - ys;
      int j1 = lower_bound(ys, ys + n, point(yl + k)) - ys;
      for (int j = j0; j < j1; j++)
        if (!used[ys[j].i])
          used[ys[j].i] = 1, ans[p]++;
      yl += k;
    } else if (ch == 'L') {
      int j0 = lower_bound(xs, xs + n, point(xl)) - xs;
      int j1 = lower_bound(xs, xs + n, point(xl + k)) - xs;
      for (int j = j0; j < j1; j++)
        if (!used[xs[j].i])
          used[xs[j].i] = 1, ans[p]++;
      xl += k; // 1 + 2
    } else if (ch == 'D') {
      // 1 2 3 4
      int j0 = upper_bound(ys, ys + n, point(yr - k)) - ys;
      int j1 = upper_bound(ys, ys + n, point(yr)) - ys;
      for (int j = j0; j < j1; j++)
        if (!used[ys[j].i])
          used[ys[j].i] = 1, ans[p]++;
      yr -= k;
    } else if (ch == 'R') {
      int j0 = upper_bound(xs, xs + n, point(xr - k)) - xs;
      int j1 = upper_bound(xs, xs + n, point(xr)) - xs;
      for (int j = j0; j < j1; j++)
        if (!used[xs[j].i])
          used[xs[j].i] = 1, ans[p]++;
      xr -= k; // 4 => 3
    }
    p = 1 - p;
  }
  for (int i = 0; i < 2; i++)
    cout << ans[i] << " \n"[i];
}
int main() {
  int T;
  cin >> T;
  while (T--)
    solve();
}
