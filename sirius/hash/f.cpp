// semenInRussia 2024
#include <iostream>
using namespace std;

const int N = 2e5, C = 31, mod = 1e9 + 7;
int p[N], h[N];

int main() {
  string s;
  cin >> s;

  for (auto &ch : s)
    ch = ch - 'a' + 1;

  int n = int(s.size());
  p[0] = 1;
  for (int i = 1; i <= 1 + n; i++)
    p[i] = 1ll * p[i - 1] * C % mod;
  for (int i = 0; i < n; i++)
    h[i + 1] = (h[i] + 1ll * p[i] * s[i]) % mod;

  int m;
  cin >> m;
  while (m--) {
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    l1--, l2--;

    int R = max(r1 - l1, r2 - l2) + 1;
    int L = -1;

    // compute LCP
    while (R - L > 1) {
      int k = (R + L) / 2;
      if (l1 + k > r1 || l2 + k > r2) {
        R = k;
        continue;
      }

      int a = 1ll * (h[l1 + k] - h[l1] + mod) * p[n - l1] % mod;
      int b = 1ll * (h[l2 + k] - h[l2] + mod) * p[n - l2] % mod;

      if (a == b)
        L = k;
      else
        R = k;
    }

    if (r1 - l1 == r2 - l2 && L >= r1 - l1) {
      cout << "=\n";
      continue;
    }

    bool ans = false; // true if <
    if (L >= min(r1 - l1, r2 - l2))
      ans = (r1 - l1) < (r2 - l2);
    else
      ans = s[l1 + L] < s[l2 + L];

    cout << (ans ? "<\n" : ">\n");
  }
}
