// Copyright (C) 2024 by semenInRussia

#include <bits/stdc++.h>
using namespace std;

const int maxc = 26;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  s += ' ';
  vector<vector<int>> cnt(maxc, vector<int>(n + 1, 0));
  for (int c = 0; c < maxc; c++)
    for (int i = 1; i < n; i++)
      cnt[c][i + 1] = cnt[c][i] + (s[i] == c + 'a');

  int q;
  cin >> q;
  for (int z = 0; z < q; z++) {
    int m;
    char c;
    cin >> m >> c;
    c -= 'a';

    int ans = 0, l = 0, r = 0;
    while (l < n) {
      if (r != n) {
        for (; r <= n; r++) {
          if ((r - l) - (cnt[c][r] - cnt[c][l]) > m) {
            r--;
            break;
          }
        }
      }
      r = min(r, n);
      ans = max(ans, r - l);
      l++;
    }

    cout << ans << '\n';
  }
}
