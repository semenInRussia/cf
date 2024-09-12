// semenInRussia 2024
#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;

#pragma GCC optimize("unroll-loops,Ofast")

const int N = 2e5 + 100;
ll b[N];
int n;

int bsearch(ll x) {
  int j = lower_bound(b, b + n + 1, x) - b;
  if (j == n + 1 || b[j] != x) {
    return 0;
  }
  return j;
}

int main() {
  cin >> n;
  ll p, q, r;
  cin >> p >> q >> r;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    b[i + 1] = b[i] + x;
  }
  bool ok = 0;
  for (int x = 0; x < n && !ok; x++) {
    int y = bsearch(b[x] + p);
    int z = bsearch(b[y] + q);
    int w = bsearch(b[z] + r);
    if (y && z && w) {
      ok = 1;
    }
  }
  cout << (ok ? "YES" : "NO");
}
