// semenInRussia 2024

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using pii = pair<int, int>;

const int maxn = 1e6;
string s;
int n;
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

  // build lcp
  int k = 0;
  for (int i = 0; i < n - 1; i++) {
    int pos = c[i];
    int j = p[pos - 1];
    while (s[j + k] == s[i + k])
      k++;
    lcp[pos] = k;
    k = max(k - 1, 0);
  }
}

const int logn = 30;
int lcpq[logn][maxn];
void sparse_build() {
  for (int i = 0; i < n; i++)
    lcpq[0][i] = lcp[i];
  for (int l = 0; l < logn; l++)
    for (int i = 0; i + (2 << l) <= n; i++)
      lcpq[l + 1][i] = min(lcpq[l][i], lcpq[l][i + (1 << l)]);
}

int find_lcp(int i, int j) {
  if (i == j)
    return n + 1;
  i = c[i], j = c[j];
  if (i > j)
    swap(i, j);

  // [i+1; j+1)
  int k = __lg(j - i);
  return min(lcpq[k][i + 1], lcpq[k][j + 1 - (1 << k)]);
}

bool cmp(pii d1, pii d2) {
  auto [l1, r1] = d1;
  auto [l2, r2] = d2;
  int lcp = find_lcp(l1, l2);
  int n1 = r1 - l1 + 1, n2 = r2 - l2 + 1;
  if (lcp >= min(n1, n2))
    return (n1 < n2) || (n1 == n2 && d1 < d2);
  return c[l1] < c[l2];
}

int main() {
  cin >> s;
  s += ' ';
  n = int(s.size());
  build(), sparse_build();

  int q;
  cin >> q;
  vector<pii> answ(q);
  for (pii &d : answ)
    cin >> d.first >> d.second;
  for (pii &d : answ)
    d.first--, d.second--;
  sort(answ.begin(), answ.end(), cmp);

  for (auto [l, r] : answ) {
    l++, r++;
    cout << l << ' ' << r << '\n';
  }
}
