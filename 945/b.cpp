// Copyright 2024 semenInRussia
#include <iostream>
using namespace std;
using ll = long long;

const int maxn = 1e5 + 100;
int a[maxn], n, b[60][maxn];

bool check(int k) {
  // query [i, i+k)
  int l = __lg(k);
  int exp = b[l][0] | b[l][0 + k - (1 << l)];
  for (int i = 0; i + k <= n; i++) {
    int res = b[l][i] | b[l][i + k - (1 << l)];
    if (exp != res)
      return false;
  }
  return true;
}

void solve() {
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i], b[0][i] = a[i];

  for (int k = 0; k < 30; k++)
    for (int i = 0; i + (2 << k) <= n; i++)
      b[k + 1][i] = b[k][i] | b[k][i + (1 << k)];

  int l = 0, r = n + 1;
  while (r > l + 1) {
    int mid = (r + l) / 2;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }

  cout << r << '\n';
}

int main() {
  int tt;
  cin >> tt;
  while (tt--)
    solve();
}
