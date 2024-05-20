// semenInRussia 2024
using namespace std;
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using ll = long long;
const int maxn = 1e6 + 100;
int n;
ll h[maxn], s[maxn], p[maxn], C = 28;
bool suf[maxn], pref[maxn];
const ll mod = (ll)1e9 + 7;

ll substr(int l, int r) { // [l; r]
  return (h[r + 1] - h[l]) * p[n - l] % mod;
}

bool check(int l, int r) { // return true, [l; r] not polyndrom
  int len = (r - l + 1);
  int mid = l + len / 2;
  if (len & 1)
    return substr(l, mid - 1) != substr(mid + 1, r);
  return substr(l, mid - 1) != substr(mid, r);
}

int main() {
  int tt;
  cin >> tt;
  p[0] = 1;
  for (int i = 0; i + 1 < maxn; i++)
    p[i + 1] = (p[i] * C) % mod;
  while (tt--) {
    char ch;
    cin >> ch;
    int i;
    for (i = 0; ch != '\n'; i++) {
      s[i] = ch - 'a' + 1;
      ch = getchar();
    }
    n = i;
    for (int i = 0; i < n; i++)
      h[i + 1] = (h[i] + s[i] * p[i]) % mod;

    reverse(s, s + n);
  }
}
