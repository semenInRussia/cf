// semenInRussia 2024
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")

const int N = 3e5, C = 256;
int p[N], c[N], _c[N];
vector<int> b[N];

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  string s;
  cin.ignore();
  getline(cin, s);
  s += '\0', n++;

  // sort by s[p[i]]
  for (int i = 0; i < n; i++)
    b[s[i]].push_back(i);
  int m = 0;
  for (int c = 0; c < C; c++)
    for (int x : b[c])
      p[m++] = x;
  for (int c = 0; c < C; c++)
    b[c].clear();

  c[p[0]] = 0;
  for (int i = 1; i < n; i++)
    c[p[i]] = c[p[i - 1]] + (s[p[i]] != s[p[i - 1]]);

  int maxc = c[p[n - 1]];

  for (int len = 1; len <= n && maxc != n - 1; len *= 2) {
    for (int i = 0; i < n; i++)
      p[i] = (p[i] - len + n) % n;

    // sort by p[i] by c[p[i]]
    for (int i = 0; i < n; i++)
      b[c[p[i]]].push_back(p[i]);
    int m = 0;
    for (int i = 0; i <= maxc; i++)
      for (int x : b[i])
        p[m++] = x;
    for (int i = 0; i <= maxc; i++)
      b[i].clear();

    // change c
    _c[p[0]] = 0;
    for (int i = 1; i < n; i++) {
      _c[p[i]] = _c[p[i - 1]];
      if (c[p[i]] != c[p[i - 1]] ||
          c[(p[i] + len) % n] != c[(p[i - 1] + len) % n])
        _c[p[i]]++;
    }
    swap(_c, c);
    maxc = c[p[n - 1]];
  }

  for (int i = 1; i < n; i++)
    cout << (p[i] + 1) << ' ';
}
