// semenInRussia 2025
#include <algorithm>
// #include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

const long long N = 2e5;
long long y[N], a[N];
long long x[N];

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

// #define HOME

using namespace __gnu_pbds;

typedef tree<pair<long long, long long>, null_type,
             less<pair<long long, long long>>, rb_tree_tag,
             tree_order_statistics_node_update>
    stree;

const long long inf = 1e9 + 100;

struct hld {
  stree v;
  long long t = 0;

  hld() { t = 0; }

  void add(long long x) { v.insert({x, t++}); }
  void er(long long x) { v.erase(v.lower_bound({x, 0})); }

  long long cnt(long long x) {
    // return v.order_of_key({x, +inf});
    // count >= x
    return (long long)v.size() - v.order_of_key({x, -inf});
  }
};

void solve() {
  long long n, m, k;
  cin >> n >> m >> k;

  vector<pair<long long, long long>> s(n);

  for (auto &[l, r] : s) {
    cin >> l >> r;
  }

  sort(s.begin(), s.end());

  for (long long i = 0; i < m; i++) {
    cin >> x[i];
  }

  hld lef, rig;

  long long j = 0;

  for (long long i = 0; i < n; i++) {
    rig.add(s[i].second - s[i].first);
  }

  long long ans = -1;

  for (long long i = 0; i < m; i++) {
    long long p = x[i];
    while (j < n && s[j].first <= p) {
      // erase from right
      rig.er(s[j].second - s[j].first);

      // insert to left
      lef.add(s[j].first + s[j].second);
      j++;
    }

    long long l = -2;
    long long r = 1e18;

    while (r - l > 1) {
      long long m = (r - l) / 2 + l;
      long long v = lef.cnt(m + p) + rig.cnt(m - p);
      if (v >= k) {
        l = m;
      } else {
        r = m;
      }
    }

    ans = max(ans, l);
  }

  cout << ans;
}

main() {
  long long tt = 1;
#ifdef home
  cin >> tt;
#endif

  while (tt--) {
    solve();
    cout << "\n";
  }
}
