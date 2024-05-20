// 2024 semenInRussia
#include <bitset>
#include <iostream>
#include <numeric>
using namespace std;
using ll = long long;

const int maxm = 55;
const int maxs = 2e5;
ll h[maxm], c[maxm];
ll d[maxm][maxs];
bitset<maxs> possible;
void solve() {
  int m, x;
  cin >> m >> x;
  for (int i = 0; i < m; i++)
    cin >> c[i] >> h[i];

  ll S = accumulate(h, h + m, 0ll);

  d[0][0] = 1;
  for (int j = 0; j <= S; j++) {
    for (int i = 0; i < m; i++) {
      d[i + 1][j] = d[i][j];
      if (i >= ((c[i] + 1) / x))
        d[i + 1][j] |= d[i - ((c[i] + 1) / x)][j - c[i]];
    }
  }

  int ans = -1;
  for (int j = 0; j <= S; j++) {
    if (d[m][j])
      ans = j;
  }

  cout << ans << '\n';
}

int main() {
  int tt;
  cin >> tt;
  while (tt--)
    solve();
}
