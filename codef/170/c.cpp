// semenInRussia 2024
#include <algorithm>
#include <iostream>
using namespace std;

const int N = 2e5;
int a[N], b[N], f[N], c[N], d[N];

void solve() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = a[i];
    c[i] = 0;
  }
  sort(b, b + n);
  int u = unique(b, b + n) - b;

  for (int i = 0; i < n; i++) {
    int x = a[i];
    int j = lower_bound(b, b + u, x) - b;
    c[j]++;
  }

  // d is prefix sum over c
  for (int i = 0; i < u; i++) {
    d[i + 1] = d[i] + c[i];
  }

  f[u - 1] = 1;
  for (int i = u - 2; i >= 0; i--) {
    f[i] = 1;
    if (b[i] + 1 == b[i + 1]) {
      f[i] = f[i + 1] + 1;
    }
  }

  int ans = -1;
  for (int i = 0; i < u; i++) {
    int s = f[i];
    s = min(s, k);
    ans = max(ans, d[i + s] - d[i]);
  }
  cout << ans << '\n';
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
