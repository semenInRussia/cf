// semenInRussia 2025
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 2e5 + 100;
int a[N], b[N], c[N];
int o[N];

const int inf = 1e9 + 100;

template <typename T> struct multset {
  int ti;
  ordered_set<pair<T, int>> s;

  multset() { ti = 0; }

  void insert(int x) { s.insert({x, ti++}); }

  T find_by_order(int i) { return s.find_by_order(i)->first; }
};

struct que {
  vector<pair<int, int>> p;
  int k;

  multset<int> a;

  que(int sz, int _k) {
    p.reserve(sz);
    k = _k;
  }

  int mnc = +inf;
  int mxc = -inf;

  void push(pair<int, int> ac) {
    auto [aa, c] = ac;
    mnc = min(mnc, c);
    mxc = max(mxc, c);
    a.insert(aa);
    p.push_back(ac);
  }

  int ans() {
    if (mxc == mnc && mxc == 0) {
      return a.find_by_order(k - 1);
    }

    sort(p.begin(), p.end(), [](auto a, auto b) {
      return a.first < b.first || (a.first == b.first && a.second > b.second);
    });

    int64_t y = 0;
    int64_t cur = 0;

    for (int i = 0; i < k; i++) {
      if (cur < p[i].first) {
        int64_t d = p[i].first - cur;
        y += d;
        cur += d;
      }
      cur += p[i].second;
    }
    return y;
  }
};

int main() {
  int n, k;
  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i] >> c[i];
  }

  for (int i = 0; i < n; i++) {
    o[i] = i;
  }

  // sort by b[i], because strength is constant
  // take k
  // sort by a[i]

  sort(o, o + n, [](int i, int j) { return b[i] < b[j]; });

  int B0 = *min_element(b, b + n);
  int Bn = *max_element(b, b + n);

  que q(n, k);

  if (B0 == Bn) {
    k = n;
  }

  for (int i = 0; i < k - 1; i++) {
    int j = o[i];
    q.push({a[j], c[j]});
  }

  const int64_t inf = 1e18 + 1000;
  int64_t ans = +inf;

  for (int j = k - 1; j < n; j++) {
    int i = o[j];
    int64_t y = b[i];
    q.push({a[i], c[i]});
    ans = min(ans, y + q.ans());
  }

  cout << ans;
}
