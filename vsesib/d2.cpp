// semenInRussia 2024
#include <cstdint>
#include <iostream>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx2")

const int N = 1e4 + 100;
int p[N];
int64_t b[N];

int n;

int a(int i, int j) {
  // i - amount of shifts
  return p[(j + i) % n];
}

int64_t pref(int i, int l, int r) {
  // return prefix sum on p[l; r), but shifted on i
  (l += i) %= n;
  (r += i) %= n;
  if (l < r) {
    return b[r] - b[l];
  }

  return b[r] + b[n] - b[l];
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  //--

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }

  for (int i = 0; i < n; i++) {
    b[i + 1] = p[i] + b[i];
  }

  int q;
  cin >> q;
  while (q--) {
    int i1, j1, i2, j2;
    cin >> i1 >> j1 >> i2 >> j2;
    i1--, j1--;
    int64_t ans = 0;
    for (int i = i1; i < i2; i++) {
      ans += pref(i, j1, j2);
    }
    cout << ans << "\n";
  }
}
