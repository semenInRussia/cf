// semenInRussia 2024
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;

    if (s.size() == 1) {
      cout << "-1\n";
      continue;
    } else if (s.size() == 2) {
      bool ok = s[0] == s[1];
      cout << (ok ? 0 : -1) << "\n";
      continue;
    }

    for (auto &c : s) {
      c -= '0';
    }

    int n = int(s.size());

    const int inf = 1e9 + 5;
    int ans = +inf;

    for (int z : {1, 2}) {
      vector<vector<int>> nxt(n, vector<int>(2, +inf));
      vector<vector<int>> prv(n, vector<int>(2, +inf));

      for (int j = 0; j < n; j++) {
        for (int c : {0, 1}) {
          prv[j][c] = +inf;
          if (j) {
            prv[j][c] = prv[j - 1][c] + 1;
          }
          if (s[j] == c) {
            prv[j][c] = 0;
          }
        }
      }

      for (int j = n - 1; j >= 0; j--) {
        for (int c : {0, 1}) {
          nxt[j][c] = +inf;
          if (j + 1 < n) {
            nxt[j][c] = nxt[j + 1][c] + 1;
          }
          if (s[j] == c) {
            nxt[j][c] = 0;
          }
        }
      }

      for (int i = 0; i < n; i++) {
        int j = n - i - 1;
        if (i >= j) {
          break;
        }
        // try nxt
        ans = min(ans, nxt[j][s[i]]);
        // try prv
        int op = prv[j][s[i]];
        if (j - op != i) {
          ans = min(ans, op);
        }
      }

      reverse(s.begin(), s.end());
    }

    cout << (ans == +inf ? -1 : ans) << "\n";
  }
}
