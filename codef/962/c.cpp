// semenInRussia 2024
#include <iostream>
using namespace std;
using ll = long long;

const int N = 2e5 + 100;
int cnta[N][27], cntb[N][27];
void solve() {
  int n, q;
  cin >> n >> q;
  string a, b;
  cin >> a >> b;
  for (int c = 0; c < 27; c++) {
    for (int i = 0; i < n; i++) {
      cnta[i + 1][c] = cnta[i][c] + ((a[i] - 'a') == c);
      cntb[i + 1][c] = cntb[i][c] + ((b[i] - 'a') == c);
    }
  }
  // cnta[c]--, cnta[d]++
  int ca[27], cb[27];
  while (q--) {
    int l, r;
    cin >> l >> r;
    l--;
    for (int c = 0; c < 27; c++) {
      ca[c] = cnta[r][c] - cnta[l][c];
      cb[c] = cntb[r][c] - cntb[l][c];
    }
    int ans = 0;
    for (int c = 0; c < 27; c++)
      ans += max(0, cb[c] - ca[c]);
    cout << ans << '\n';
  }
}

int main() {
  int tt;
  cin >> tt;
  while (tt--)
    solve();
}
