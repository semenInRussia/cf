// semenInRussia 2025
#include <cstdint>
#include <iostream>
#include <vector>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template <typename T>
using sset =
    tree<T, null_type, less, rb_tree_tag, tree_order_statistics_node_update>;

using namespace std;

const int inf = 1e9 + 100;
const int mod = 1e9 + 7;

int main() {
  int n;
  cin >> n;

  vector<pair<int, int>> p(n);

  for (auto &x : p) {
    cin >> x.first >> x.second;
  }

  int ans = 0;

  for (int b = 1; b < (1 << n); b++) {
    int mnx = +inf;
    int mxx = -inf;

    int mny = +inf;
    int mxy = -inf;

    for (int j = 0; j < n; j++) {
      if ((b >> j) & 1) {
        mnx = min(mnx, p[j].first);
        mxx = max(mxx, p[j].first);

        mny = min(mny, p[j].second);
        mxy = max(mxy, p[j].second);
      }
    }

    (ans += 1ll * (mxx - mnx) * (mxy - mny) % mod) %= mod;
  }

  cout << ans;
}
