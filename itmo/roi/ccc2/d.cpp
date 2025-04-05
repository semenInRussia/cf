// semenInRussia 2025
#ifndef home
#pragma GCC optimize("O3,unroll-loops")
#endif
#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <set>
#ifndef home
#pragma GCC target("avx2")
#endif

using namespace std;

const int N = 1e4;
int a[N], b[N];
int ans[N];

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }

  sort(a, a + n);
  sort(b, b + n);

  int q;
  cin >> q;

  int l, r;
  cin >> l >> r;
  // assert(l == r && r == 1);

  for (int k = 0; k <= n; k++) {
    if (k == 0) {
      ans[k] = 1;
      continue;
    }

    for (int msk = 0; msk < (1 << n); msk++) {
      if (__builtin_popcount(msk) != k) {
        continue;
      }
      set<int> A, A2;
      for (int i = 0; i < n; i++) {
        if ((msk >> i) & 1) {
          A.insert(a[i]);
        } else {
          A2.insert(a[i]);
        }
      }
      set<int> s(b, b + n);
      bool ok = true;
      for (int x : A) {
        auto it = s.begin();
        if (*it > x) {
          ok = false;
          break;
        }
        s.erase(it);
      }
      for (int x : A2) {
        auto it = s.upper_bound(x);
        if (it == s.end()) {
          ok = false;
          break;
        }
        s.erase(it);
      }
      ans[k] += ok;
    }
  }

  int sum = 0;

  for (int i = 0; i <= n; i++) {
    cout << ans[i] << " ";
    sum += ans[i];
  }

  cout << " => " << sum;
}
