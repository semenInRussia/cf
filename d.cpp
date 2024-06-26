// semenInRussia 2024
// https://codeforces.com/problemset/problem/1985/G
#include <iostream>
using namespace std;

const int mod = 1e9 + 7;
int binpow(int a, int k) { // a^k
  int ans = 1;
  while (k) {
    if (k & 1)
      ans = (1ll * ans * a) % mod;
    k >>= 1;
    a = (1ll * a * a) % mod;
  }
  return ans;
}

int v;
int f(int s) { // all N < 10^s
  return binpow(v, s);
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int l, r, k;
    cin >> l >> r >> k;
    v = 0;
    for (int i = 0; i < 10; i += k)
      v++;
    cout << (f(r) - f(l) + mod) % mod << '\n';
  }
}
