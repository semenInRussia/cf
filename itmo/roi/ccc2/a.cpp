// semenInRussia 2025
#pragma GCC optimize("Ofast")
#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <vector>
#ifndef home
#pragma GCC target("avx2")
#endif

using namespace std;

using ll = long long;

const int N = 1e6 + 1;
int a[N];
ll b[N];

const ll infll = 1e18;

const int L = 20;
ll st1[N][L], st2[N][L];

ll mn(int l, int r) {
  int k = __lg(r - l);
  return min(st1[l][k], st1[r - (1 << k)][k]);
}

ll mx(int l, int r) {
  int k = __lg(r - l);
  return max(st2[l][k], st2[r - (1 << k)][k]);
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n, q;
  cin >> n >> q;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[i + 1] = b[i] + a[i];
  }

  // first; fill dp

  for (int i = 0; i <= n; i++) {
    st2[i][0] = st1[i][0] = b[i];
  }

  for (int l = 0; l + 1 < L; l++) {
    for (int i = 0; i + (2 << l) <= n + 1; i++) {
      st1[i][l + 1] = min(st1[i][l], st1[i + (1 << l)][l]);
      st2[i][l + 1] = max(st2[i][l], st2[i + (1 << l)][l]);
    }
  }

  for (int i = 0; i < q; i++) {
    int typ;
    cin >> typ;

    if (typ == 2) {
      int j, v;
      cin >> j >> v;
      --j;
      a[j] = v;
      for (int i = 0; i < n; i++) {
        b[i + 1] = b[i] + a[i];
      }

      for (int i = 0; i <= n; i++) {
        st2[i][0] = st1[i][0] = b[i];
      }

      for (int l = 0; l + 1 < L; l++) {
        for (int i = 0; i + (2 << l) <= n + 1; i++) {
          st1[i][l + 1] = min(st1[i][l], st1[i + (1 << l)][l]);
          st2[i][l + 1] = max(st2[i][l], st2[i + (1 << l)][l]);
        }
      }
      continue;
    }

    int l, r;
    cin >> l >> r;
    --l;

    int64_t sum = b[r] - b[l];
    int64_t ans = abs(sum);

    auto t = mn(l, r);
    ans = max(ans, min(abs(b[r] - t), abs(b[l] - t)));
    t = mx(l, r);
    ans = max(ans, min(abs(b[r] - t), abs(b[l] - t)));

    for (int j = l + 1; j < r; j++) {
      auto x = abs(mx(l, j) - b[l]);
      auto y = abs(mn(j, r) - sum - b[l]);
      ans = max(ans, min(x, y));
    }

    cout << ans << "\n";
  }
}
