// semenInRussia 2025
#pragma GCC optimize("O3,unroll-loops")

#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <set>
#include <vector>

#pragma GCC target("avx2")

using namespace std;

struct fenw {
  vector<int> t;
  int n;

  fenw(int _n) : n(_n) { t.resize(n + 1, -1); }

  void add(int j, int v) {
    j++;
    for (; j <= n; j += j & -j) {
      t[j] = max(t[j], v);
    }
  }

  int qry(int r, int x) {
    r++;
    // on [0; r] >= x
    for (; r > 0; r -= r & -r) {
      auto it = t[r];
      if (it > x) {
        return true;
      }
    }
    return false;
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n;
  cin >> n;

  vector<int> ord(n * 2), ql(n), qr(n);

  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    l--;
    ord[i] = l;
    ord[i + n] = r;
    ql[i] = l;
    qr[i] = r;
  }

  sort(ord.begin(), ord.end());
  ord.resize(unique(ord.begin(), ord.end()) - ord.begin());

  fenw t(ord.size());

  vector<pair<int, int>> p(n);
  multiset<pair<int, int>> s1, s2;

  const int inf = 2e9 + 100;

  s1.insert({inf, -1});
  s2.insert({inf, -1});

  for (int i = 0; i < n; i++) {
    int l = ql[i];
    int r = qr[i];

    l = lower_bound(ord.begin(), ord.end(), l) - ord.begin();
    r = lower_bound(ord.begin(), ord.end(), r) - ord.begin();

    if (t.qry(l, r)) {
      cout << (int(s1.size()) - 1) << " ";
      continue;
    }

    int l1 = l;
    int r1 = r;

    // find all lj >= l && lj < r
    while (1) {
      auto it = s1.lower_bound({l, -1});
      if (it == s1.end() || it->first >= r) {
        break;
      }
      auto [lj, cmp] = *it;
      auto [_lj, rj] = p[cmp];
      s1.erase(it);
      s2.erase(s2.find({rj, cmp}));
      l1 = min(lj, l1);
      r1 = max(rj, r1);
    }

    while (1) {
      auto it = s2.upper_bound({l, +inf});
      if (it == s2.end() || it->first > r) {
        break;
      }
      auto [rj, cmp] = *it;
      auto [lj, _rj] = p[cmp];
      s2.erase(it);
      s1.erase(s1.find({lj, cmp}));
      l1 = min(lj, l1);
      r1 = max(rj, r1);
    }

    p[i] = {l1, r1};
    s1.insert({l1, i});
    s2.insert({r1, i});
    t.add(l1, r1);
    assert(s1.size() == s2.size());
    cout << (int(s1.size()) - 1) << " ";
  }
}
