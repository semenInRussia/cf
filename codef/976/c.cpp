// semenInRussia 2024
// https://codeforces.com/contest/2020/problem/C
using namespace std;
#include <iostream>
#include <map>
#include <vector>
using ll = long long;

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")

const int L = 61;

void solve() {
  ll b, c, d;
  cin >> b >> c >> d;
  // (a | b) - (a & c) = d
  bool ok = 1;
  ll a = 0;
  for (int i = 0; i < L && ok; i++) {
    int x = (b >> i) & 1;
    int y = (c >> i) & 1;
    int z = (d >> i) & 1;

    // a=1
    // d=1-y
    //
    // a=0
    // d=x

    // we can: either not y, either x
    if (x == z) {
      // add 0
    } else if (!y == z) {
      a |= 1ll << i;
    } else {
      ok = 0;
    }
  }

  //
  cout << (ok ? a : -1) << '\n';
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
