// semenInRussia 2024
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int N = 2e5 + 100;
int p[N], c[N], _c[N], lcp[N];
vector<int> b[N];

int main() {
  string s;
  cin >> s;
  s += '$';
  int n = int(s.size());

  for (int i = 0; i < n; i++)
    p[i] = i;
  sort(p, p + n, [&s](int i, int j) { return s[i] < s[j]; });
  c[p[0]] = 0;
  for (int i = 1; i < n; i++) {
    c[p[i]] = c[p[i - 1]] + (s[p[i]] != s[p[i - 1]]);
  }

  int maxc = p[n - 1];
  for (int len = 1; len < n && maxc != n - 1; len *= 2) {
    for (int i = 0; i < n; i++)
      p[i] = (p[i] - len + n) % n;

    // sort by p[i] by c[p[i]]
    for (int i = 0; i < n; i++)
      b[c[p[i]]].push_back(p[i]);
    int m = 0;
    for (int i = 0; i < n; i++)
      for (int x : b[i])
        p[m++] = x;
    for (int i = 0; i < n; i++)
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
    maxc = p[n - 1];
  }

  int k = 0;
  for (int i = 0; i < n - 1; i++) {
    int b = p[c[i] - 1];
    while (s[i + k] == s[b + k])
      k++;
    lcp[c[i]] = k;
    k = max(0, k - 1);
  }

  using ll = long long;
  ll ans = 0;

  for (int i = 1; i < n; i++) {
    int len = n - p[i] - 1; // [0; n) but ignore $
    ans += len;             // unique substrings: [1, 2, 3, ..., len]
    int lc = max(lcp[i + 1], lcp[i]);
    ans -= lc;

    // but if this LCP is new, then still add it
    if (lcp[i - 1] < lcp[i])
      ans += abs(lcp[i] - lcp[i - 1]);
  }

  cout << ans;
}
