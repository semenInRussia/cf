#include <iostream>
using namespace std;
using ll = long long;
#pragma GCC optimize("unroll-loops,O3")

const int maxm = 100, H = 1e5, inf = 1e9;
int c[maxm], h[maxm];
ll d[H + 1];
int main() {
  ios::sync_with_stdio(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int m, x;
    cin >> m >> x;
    int S = 0;
    for (int i = 0; i < m; i++)
      cin >> c[i] >> h[i], S += h[i];
    d[0] = 0;
    for (int i = 1; i <= H; i++)
      d[i] = -inf;
    for (int i = 0; i < m; i++) {
      for (int j = S; j >= h[i]; j--)
        if (d[j - h[i]] >= c[i])
          d[j] = max(d[j], d[j - h[i]] - c[i]);
      for (int j = 0; j <= S; j++)
        if (d[j] >= 0)
          d[j] += x;
    }
    int ans = 0;
    for (int j = 0; j <= S; j++)
      if (d[j] >= 0)
        ans = j;
    cout << ans << '\n';
  }
}
