// suffix array semenInRussia 2024
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using pii = pair<int, int>;

const int maxn = 1e6;
int sa[maxn], c[maxn], cn[maxn];

void sufarr(string &s) {
  int n = (int)s.size();
  for (int i = 0; i < n; i++)
    sa[i] = i;

  sort(sa, sa + n, [&s](int i, int j) { return s[i] < s[j]; });
  c[sa[0]] = 0;
  for (int i = 1; i < n; i++)
    c[sa[i]] = c[sa[i - 1]] + (s[sa[i]] != s[sa[i - 1]]);

  vector<int> b[maxn];
  for (int len = 1; len < n; len *= 2) {
    for (int i = 0; i < n; i++)
      sa[i] = (sa[i] - len + n) % n;

    // sort p with c
    for (int i = 0; i < n; i++)
      b[i].clear();
    for (int i = 0; i < n; i++)
      b[c[sa[i]]].push_back(sa[i]);
    int m = 0;
    for (int i = 0; i < n; i++)
      for (int x : b[i])
        sa[m++] = x;

    // make c[]
    cn[sa[0]] = 0;
    for (int i = 1; i < n; i++) {
      pii prv = {c[sa[i - 1]], c[(sa[i - 1] + len) % n]};
      pii cur = {c[sa[i]], c[(sa[i] + len) % n]};
      cn[sa[i]] = cn[sa[i - 1]] + (prv != cur);
    }
    swap(cn, c);
  }
}

int main() {
  string s;
  cin >> s;
  s += '$';
  sufarr(s);
  for (int i = 0; i < int(s.size()); i++)
    cout << sa[i] << ' ';
}
