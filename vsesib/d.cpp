// semenInRussia 2024
#include <cstdint>
#include <iostream>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx2")

const int N = 2e5 + 100;
int p[N];

int n;

int a(int i, int j) { return p[(j + i) % n]; }

int64_t s[N];

int64_t pref(int i, int l, int r) {
  // return prefix sum on p[l; r), but shifted on i
  if (r - l <= 0) {
    return 0ll;
  }
  (l += i) %= n;
  (r += i) %= n;
  if (l < r) {
    return s[r] - s[l];
  }

  return max(s[r] + s[n] - s[l], 0ll);
}

int64_t b(int i2, int j2) {
  int64_t ans = 0;

  for (int i = 0; i < i2; i++) {
    ans += pref(i, 0, j2);
  }

  return ans;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  //--

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }

  for (int i = 0; i < n; i++) {
    s[i + 1] = s[i] + p[i];
  }

  int q;
  cin >> q;
  while (q--) {
    int i1, j1, i2, j2;
    cin >> i1 >> j1 >> i2 >> j2;
    i1--, j1--;
    int64_t v = b(i2, j2) - b(i1, j2) - b(i2, j1) + b(i1, j1);
    cout << v << "\n";
  }
}
