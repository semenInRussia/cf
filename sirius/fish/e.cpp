// semenInRussia 2024
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define isz(a) int((a).size())

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC optimize("avx2")

const int N = 1.001e6;
vector<int> b[N];
int p[N], _c[N], c[N];
string words[N];

// I will solve with Suffix Array, because I am writing that very easily

int main() {
  cin.sync_with_stdio(0);
  cin.tie(nullptr);

  int m;
  cin >> m;
  for (int i = 0; i < m; i++)
    cin >> words[i];

  string s;
  cin >> s;

  // --- Build Suffix Array

  s.push_back('$');
  int n = int(s.size());

  for (int i = 0; i < n; i++)
    p[i] = i;
  sort(p, p + n, [&s](int i, int j) { return s[i] < s[j]; });
  c[p[0]] = 0;
  for (int i = 1; i < n; i++)
    c[p[i]] = c[p[i - 1]] + (s[p[i - 1]] != s[p[i]]);

  int maxc = -1;
  for (int len = 1; len < n && maxc != n - 1; len *= 2) {
    maxc = c[p[n - 1]];
    for (int i = 0; i < n; i++)
      p[i] = (p[i] - len + n) % n;

    // sort by c[p[i]] (count sort)
    for (int i = 0; i < n; i++)
      b[c[p[i]]].push_back(p[i]);
    int m = 0;
    for (int i = 0; i <= maxc; i++)
      for (int x : b[i])
        p[m++] = x;
    for (int i = 0; i < n; i++)
      b[i].clear();

    // build c[i]
    _c[p[0]] = 0;
    for (int i = 1; i < n; i++) {
      _c[p[i]] = _c[p[i - 1]];
      if (c[p[i]] != c[p[i - 1]] ||
          c[(p[i] + len) % n] != c[(p[i - 1] + len) % n])
        _c[p[i]]++;
    }
    swap(_c, c);
  }

  // --- End Build

  auto lcm = [&s, n](int i, string &wrd) {
    int j = 0;
    int m = isz(wrd);
    while (j < m && s[i + j] == wrd[j])
      j++;
    return j;
  };

  for (int i = 0; i < m; i++) {
    int l = -1, r = n;
    bool ok = 0;

    while (r - l > 1 && !ok) {
      int m = (r + l) / 2;
      int lc = lcm(p[m], words[i]);
      if (lc == isz(words[i]))
        ok = 1;
      else if (s[p[m] + lc] < words[i][lc])
        l = m;
      else
        r = m;
    }

    cout << (ok ? "YES\n" : "NO\n");
  }
}
