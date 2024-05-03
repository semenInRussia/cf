// Copyright 2024 semenInRussia

#include <cctype>
#include <iostream>
#include <vector>

using namespace std;

#define null make_pair(-1, -1)

pair<int, int> min_pos(pair<int, int> a, pair<int, int> b) {
  if (a == null)
    return b;
  if (b == null)
    return a;

  if (a.first != b.first) {
    return min(a, b);
  }

  if (a.second < b.second) {
    return a;
  } else {
    return b;
  }
}

char at(vector<string> &t, int i, int j) {
  if (i >= t.size() || j >= t[0].size() || i < 0 || j < 0)
    return 0;

  return t[i][j];
}

pair<int, int> at(vector<vector<pair<int, int>>> &t, int i, int j) {
  if (i >= t.size() || j >= t[0].size() || i < 0 || j < 0)
    return null;

  return t[i][j];
}

void solve() {
  int n, m;
  cin >> n >> m;

  char pl;
  cin >> pl;
  pl = toupper(pl);

  vector<string> t(n);
  for (auto &row : t)
    cin >> row;

  char op = ('W' + 'B') - pl;

  int inc = (pl == 'W' ? -1 : +1);
  int beg = (pl == 'W' ? n - 1 : 0);
  int end = n - 1 - beg;

  vector<vector<pair<int, int>>> p(n);

  for (int i = beg; i != end + inc; i += inc) {
    p[i].resize(m);
    for (int j = 0; j < m; j++) {
      if (t[i][j] == pl) {
        p[i][j] = {i + 1, j + 1};
      } else {
        p[i][j] = null;
      }
    }
  }

  for (int i = beg; i != end + inc; i += inc) {
    for (int j = 0; j < m; j++) {
      if (p[i][j] == null)
        continue;

      if (at(t, i + inc, j - 1) == op && at(t, i + 2 * inc, j - 2) == '.') {
        p[i + 2 * inc][j - 2] = min_pos(p[i + 2 * inc][j - 2], p[i][j]);
      }

      if (at(t, i + inc, j + 1) == op && at(t, i + 2 * inc, j + 2) == '.') {
        p[i + 2 * inc][j + 2] = min_pos(p[i + 2 * inc][j + 2], p[i][j]);
      }
    }
  }

  pair<int, int> ans = null;

  int i = end - inc;
  for (int j = 0; j < m; j++) {
    if (at(t, i, j) != pl)
      continue;

    if (at(t, end, j - 1) == '.' || at(t, end, j + 1) == '.')
      ans = min_pos(ans, {i + 1, j + 1});
  }

  for (auto pos : p[end]) {
    ans = min_pos(ans, pos);
  }

  cout << ans.first << ' ' << ans.second << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();

  return 0;
}
