// semenInRussia 2025
#include <algorithm>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

const int N = 120;
int dp[N][N];

char s[N];
int n;

int p[N], c[N];
int lcp[N];

struct mv {
  int offs = -1;
  int repeat = -1;
};

mv prv[N][N];

void build() {
  for (int i = 0; i < n; i++) {
    p[i] = i;
  }

  sort(p, p + n, [](int i, int j) { return memcmp(&s[i], &s[j], n) < 0; });

  for (int i = 0; i < n; i++) {
    c[p[i]] = i;
  }
  int k = 0;
  for (int i = 0; i < n - 1; i++) {
    int j = p[c[i] - 1];
    while (s[i + k] == s[j + k]) {
      ++k;
    }
    lcp[c[i] - 1] = k;
    if (k > 0) {
      --k;
    }
  }
}

string restore(int i, int j) {
  if (dp[i][j] == j - i) {
    return string(s + i, s + j);
  }
  if (prv[i][j].repeat != -1) {
    int k = prv[i][j].repeat;
    string f = to_string(k) + "(";
    f += restore(i, i + (j - i) / k);
    f += ')';
    return f;
  }
  int m = prv[i][j].offs;
  return restore(i, m) + restore(m, j);
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  freopen("folding.in", "r", stdin);
  freopen("folding.out", "w", stdout);
  scanf("%s", s);
  n = strlen(s) + 1;
  build();
  --n;

  for (int i = 0; i < n; i++) {
    dp[i][i + 1] = 1;
  }

  // for (int i = 0; i < n; i++) {
  //   cout << lcp[i] << ". ";
  //   for (int j = p[i]; j < n; j++) {
  //     cout << s[j];
  //   }
  //   cout << "\n";
  // }

  for (int len = 2; len <= n; len++) {
    for (int i = 0; i + len <= n; i++) {
      int j = i + len;
      int sz = j - i;
      dp[i][j] = sz;
      for (int k = 1; k < sz; k++) {
        if (sz % k) {
          continue;
        }
        int l = n;
        int r = -1;
        for (int f = i; f < j; f += k) {
          l = min(l, c[f]);
          r = max(r, c[f]);
        }
        int mn = n;
        for (int f = l; f < r; f++) {
          mn = min(mn, lcp[f]);
        }
        if (mn >= k) {
          int op = int(to_string(sz / k).size()) + 2 + dp[i][i + k];
          if (op < dp[i][j]) {
            dp[i][j] = op;
            prv[i][j] = {-1, sz / k};
          }
        }
      }

      for (int k = i + 1; k < j; k++) {
        int op = dp[i][k] + dp[k][j];
        if (op < dp[i][j]) {
          dp[i][j] = op;
          prv[i][j] = {k, -1};
        }
      }
    }
  }

  // cerr << dp[0][n] << "\n";
  cout << restore(0, n) << "\n";
}
