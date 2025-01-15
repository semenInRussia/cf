// semenInRussia 2025
#include <cstdint>
#include <iostream>

using namespace std;

const int N = 1510;
int dp[N][N];

string t[N];

int len[N][N];

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> t[i];
    cin >> dp[i][n];
  }

  for (int i = 0; i < n; i++) {
    cin >> dp[n][i];
  }

  int64_t ans = 0;

  for (int i = n - 1; i >= 0; i--) {
    for (int j = n - 1; j >= 0; j--) {
      if (t[i][j] == 'R') {
        dp[i][j] = dp[i][j + 1];
      } else {
        dp[i][j] = dp[i + 1][j];
      }
      ans += dp[i][j];
    }
  }

  // len[0][0] = 1;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      len[i][j]++;
      if (t[i][j] == 'R') {
        len[i][j + 1] += len[i][j];
      } else {
        len[i + 1][j] += len[i][j];
      }
    }
  }

  cout << ans << "\n";

  int q;
  cin >> q;
  while (q--) {
    int i, j;
    cin >> i >> j;
    i--, j--;

    for (int k : {-1, +1}) {
      int ui = i;
      int uj = j;

      while (true) {
        if (ui != i || uj != j) {
          len[ui][uj] += len[i][j] * k;
        }
        if (ui == n || uj == n) {
          break;
        }
        if (t[ui][uj] == 'R') {
          uj++;
        } else {
          ui++;
        }
      }

      ans += 1ll * k * len[i][j] * dp[ui][uj];

      if (k == -1) {
        t[i][j] = 'R' + 'D' - t[i][j];
      }
    }

    cout << ans << "\n";
  }
}
