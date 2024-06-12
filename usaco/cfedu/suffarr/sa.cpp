// semenInRussia 2024
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
using pii = pair<int, int>;
using ll = long long;

const int maxn = 1e6;
string s;
int n;
ll lcp[maxn];
vector<int> b[maxn];
int c[maxn], sa[maxn], cn[maxn];

void sufarr() {
  for (int i = 0; i < n; i++)
    sa[i] = i;
  sort(sa, sa + n, [](int i, int j) { return s[i] < s[j]; });
  c[sa[0]] = 0;
  for (int i = 1; i < n; i++)
    c[sa[i]] = c[sa[i - 1]] + (s[sa[i]] != s[sa[i - 1]]);

  for (int len = 1; len < n; len *= 2) {
    for (int i = 0; i < n; i++)
      sa[i] = (sa[i] - len + n) % n;

    // sort sa[] by c[]
    for (int i = 0; i < n; i++)
      b[i].clear();
    for (int i = 0; i < n; i++)
      b[c[sa[i]]].push_back(sa[i]);
    int m = 0;
    for (int i = 0; i < n; i++)
      for (int x : b[i])
        sa[m++] = x;

    // build c[] again
    cn[sa[0]] = 0;
    for (int i = 1; i < n; i++) {
      pii cur = {c[sa[i]], c[(sa[i] + len) % n]};
      pii prv = {c[sa[i - 1]], c[(sa[i - 1] + len) % n]};
      cn[sa[i]] = cn[sa[i - 1]] + (cur != prv);
    }
    swap(c, cn);
  }
}

int main() {
  cin >> s;
  s += '$';
  n = int(s.size());
  sufarr();

  int k = 0;
  for (int i = 0; i < n - 1; i++) {
    int pos = c[i];
    int a = i, b = sa[pos - 1];
    while (s[a + k] == s[b + k])
      k++;
    lcp[pos] = k;
    k = max(k - 1, 0);
  }

  ll ans = 0;
  for (int i = 0; i < n; i++)
    ans += sa[i] - lcp[i];
  cout << ans;
}
