// semenInRussia 2024
#include <algorithm>
#include <cstdint>
#include <iostream>
using namespace std;

const int inf = 1e9 + 5;

using ll = long long;

const int N = 200000;
int w[N], _w[N];
int f[N];

ll ans[N];

int main() {
  int n, m;
  cin >> n >> m;
  ll k;
  cin >> k;

  for (int i = 0; i < n; i++) {
    cin >> w[i];
    _w[i] = w[i];
  }

  int v = +inf;
  int u = 0;
  for (int i = 0; i < m; i++) {
    cin >> f[i];
    f[i]--;
    int j = f[i];
    v = min(w[j], v);
    u = max(w[j], u);
  }

  sort(w, w + n);

  int p = 0;
  int r = 0;
  int pos = -1;
  for (int i = 0; i < n && k >= 0; i++) {
    if (w[i] == v && (i == 0 || w[i - 1] != w[i])) {
      r = 0;
      pos = i;
    }
    if (i && w[i] != w[i - 1]) {
      p++;
      r++;
    }
    k -= p;
    ans[i] = p;
  }

  if (k < 0) {
    cout << "IMPOSSIBLE";
    return 0;
  }

  auto x = k / (n - pos);

  for (int i = pos; i < n; i++) {
    ans[i] += x;
  }

  k -= x * (n - pos);

  // d * (n - pos) <= k

  int t = lower_bound(w, w + n, u) - w;
  auto d = k / (n - t);

  for (int i = t; i < n; i++) {
    ans[i] += d;
  }

  // also we can add d;

  cout << "POSSIBLE\n";
  for (int i = 0; i < n; i++) {
    int wi = _w[i];
    int j = lower_bound(w, w + n, wi) - w;
    cout << ans[j] << " ";
  }
}
