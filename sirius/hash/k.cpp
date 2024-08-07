// semenInRussia 2024
#include <iostream>
using namespace std;
using ull = unsigned long long;

const int C = 31, N = 5.1e6;
ull h[N], p[N];
int n;

ull substr(int l, int r) { return p[n - l] * (h[r] - h[l]); }

int main() {
  string s;
  cin >> s;
  n = int(s.size());
  for (char &ch : s)
    ch = ch - 'a' + 1;

  p[0] = 1;
  for (int i = 1; i <= n; i++)
    p[i] = p[i - 1] * C;
  for (int i = 0; i < n; i++)
    h[i + 1] = h[i] + p[i] * s[i];

  int ans = 0;
  for (int k = 1; k <= n; k++) {
    if (n % k)
      continue;
    ull o = substr(0, k);
    bool ok = 1;
    for (int i = k; i + k <= n && ok; i += k) {
      ull cur = substr(i, i + k);
      if (cur != o)
        ok = 0;
    }
    if (ok) {
      ans = k;
      break;
    }
  }
  cout << ans;
}
