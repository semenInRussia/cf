// Copyright 2024 semenInRussia

#include <cctype>
#include <iostream>
#include <vector>

using namespace std;

pair<int, int> amin(pair<int, int> a, pair<int, int> b) {
  // pair<int, int> null = {0, 0};

  if (a == make_pair(0, 0))
    return b;
  if (b == make_pair(0, 0))
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
    return {-1, -1};

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
        p[i][j] = {0, 0};
      }
    }
  }

  for (int i = beg; i != end + inc; i += inc) {
    for (int j = 0; j < m; j++) {
      if (p[i][j] == make_pair(0, 0))
        continue;

      if (at(t, i + inc, j - 1) == op && at(t, i + 2 * inc, j - 2) == '.') {
        p[i + 2 * inc][j - 2] = amin(p[i + 2 * inc][j - 2], p[i][j]);
      }

      if (at(t, i + inc, j + 1) == op && at(t, i + 2 * inc, j + 2) == '.') {
        p[i + 2 * inc][j + 2] = amin(p[i + 2 * inc][j + 2], p[i][j]);
      }
    }
  }

  pair<int, int> res = {0, 0};

  int i = end - inc;
  for (int j = 0; j < m; j++) {
    if (at(t, i, j) == pl &&
        (at(t, end, j - 1) == '.' || at(t, end, j + 1) == '.'))
      res = amin(res, {i + 1, j + 1});
  }

  for (auto pj : p[end]) {
    if (pj != make_pair(0, 0)) {
      res = amin(res, pj);
    }
  }

  if (res == make_pair(0, 0)) {
    cout << "-1 -1" << endl;
  } else {
    cout << res.first << ' ' << res.second << endl;
  }
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();

  return 0;
}
