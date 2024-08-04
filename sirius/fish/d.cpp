
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int M = 1e4;
int nxt[M][26];

int main() {
  string s, p;
  cin >> s >> p;

  int n = int(s.size());
  int m = int(p.size());

  for (int i = 0; i < n; ++i) {
    s[i] -= 'a';
  }

  for (int i = 0; i < m; ++i) {
    p[i] -= 'a';
  }

  for (int i = 1; i < m; ++i) {
    int prev = nxt[i - 1][p[i - 1]];
    nxt[i - 1][p[i - 1]] = i;
    for (int j = 0; j < 27; j++)
      nxt[i][j] = nxt[prev][j];
  }
  nxt[m - 1][p[m - 1]] = m;

  vector<int> max_taken(m, -n - 1);
  max_taken[0] = 0;
  for (int i = 0; i < n; ++i) {
    vector<int> nxt_taken = max_taken;
    for (int j = 0; j < m; ++j) {
      int cur = nxt[j][s[i]];
      if (cur < m) {
        nxt_taken[cur] = max(nxt_taken[cur], max_taken[j] + 1);
      }
    }
    max_taken = nxt_taken;
  }

  int result = 0;
  for (int i = 0; i < m; ++i) {
    result = max(result, max_taken[i]);
  }

  cout << n - result;
}
