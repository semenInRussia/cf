// semenInRussia 2024

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;
using pii = pair<int, int>;

const int maxn = 2e5 + 1000;
string s;
int m; // size of first string
int n; // size of s=(s+t)
vector<int> b[maxn];
int p[maxn], c[maxn], _c[maxn];
int lcp[maxn];
void build() {
  // build Suffix Array
  for (int i = 0; i < n; i++)
    p[i] = i;
  sort(p, p + n, [](int i, int j) { return s[i] < s[j]; });
  c[p[0]] = 0;
  for (int i = 1; i < n; i++)
    c[p[i]] = c[p[i - 1]] + (s[p[i]] != s[p[i - 1]]);

  for (int len = 1; len < n; len *= 2) {
    for (int i = 0; i < n; i++)
      p[i] = (p[i] - len + n) % n;

    for (int i = 0; i < n; i++)
      b[c[p[i]]].push_back(p[i]);
    int m = 0;
    for (int i = 0; i < n; i++)
      for (int x : b[i])
        p[m++] = x;
    for (int i = 0; i < n; i++)
      b[i].clear();

    _c[p[0]] = 0;
    for (int i = 1; i < n; i++) {
      pii prv = {c[p[i - 1]], c[(p[i - 1] + len) % n]};
      pii cur = {c[p[i]], c[(p[i] + len) % n]};
      _c[p[i]] = _c[p[i - 1]] + (prv != cur);
    }
    swap(_c, c);
  }

  // build array `lcp`
  int k = 0;
  for (int i = 0; i < n - 1; i++) {
    int pos = c[i];
    int a = i, b = p[pos - 1];
    while (max(a, b) + k < n && s[a + k] == s[b + k])
      k++;
    lcp[pos] = k;
    k = max(0, k - 1);
  }
}

int main() {
  string t;
  cin >> s >> t;
  m = int(s.size());
  s += '#', s += t, s += '$';
  n = int(s.size());
  build();

  pii ans = {-1, 0}; // first is string len, second is string index
  int a = -1, b = -1;
  for (int i = 0; i < n; i++) {
    if (p[i] > m) // type B
      b = i;
    else // type A
      a = i;
    if (a == -1 || b == -1)
      continue;
    int k = INT32_MAX; // lcp(a, b) = min(lcp[a+1..b])
    for (int i = min(a, b) + 1; i <= max(a, b); i++)
      k = min(k, lcp[i]);

    pii cur = {k, p[i]};
    if (cur.first != ans.first)
      ans = max(cur, ans); // min by lexicographical
  }
  cout << s.substr(ans.second, ans.first);
}
