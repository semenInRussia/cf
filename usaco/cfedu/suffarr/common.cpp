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
  // build suffix array
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
    int j = p[c[i] - 1];
    while (s[i + k] == s[j + k])
      k++;
    lcp[c[i]] = k;
    k = max(0, k - 1);
  }
}

int main() {
  // string t;
  // cin >> s >> t;
  // m = int(s.size());
  // s += '#', s += t, s += '$';
  // n = int(s.size());
  cin >> s;
  build();
  for (int i = 0; i < n; i++) {
    cout << s.substr(p[i]) << "\n";
  }
  // pii ans{0, 0};
  // for (int i = 1; i < n; i++)
  //   if ((p[i] < m) != (p[i - 1] < m))
  //     ans = max(ans, {lcp[i], -i});
  // cout << s.substr(p[-ans.second], ans.first);
}
