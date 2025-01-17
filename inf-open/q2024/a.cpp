// semenInRussia 2024
#include <iostream>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,fma,bmi2,tune=native")

const int N = 2e5 + 100, K = 'z' - 'a' + 2;
int nxt[N][K];

string s, w;

bool check(int k) {
  int n = int(s.size());

  int j = 0; // cursor at s
  for (auto c : w) {
    if (j >= n) {
      return 0;
    }
    int p = nxt[j][int(c)];
    if (p == -1) {
      return 0;
    }
    j = p + k;
  }

  return 1;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  // ---

  int n, m;
  cin >> n >> m >> s;

  for (auto &c : s) {
    c -= 'a';
  }

  // build nxt[i][c] - next after i occurance of character c in s
  for (int c = 0; c < K; c++) {
    nxt[n][c] = -1;
    for (int i = n - 1; i >= 0; i--) {
      nxt[i][c] = nxt[i + 1][c];
      if (s[i] == c) {
        nxt[i][c] = i;
      }
    }
  }

  for (int i = 0; i < m; i++) {
    cin >> w;

    for (auto &c : w) {
      c -= 'a';
    }

    int l = 0;
    int r = n;
    while (r - l > 1) {
      int m = (r + l) / 2;
      if (check(m)) {
        l = m;
      } else {
        r = m;
      }
    }
    cout << (l == 0 ? -1 : l) << "\n";
  }
}
