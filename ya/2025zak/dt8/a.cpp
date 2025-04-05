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
using stree =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct multree {
  stree<pair<int, int>> t;
  int ti = 0;

  int size() { return (int)t.size(); }

  void insert(int x) { t.insert({x, ti++}); }

  void erase(int x) {
    auto it = t.lower_bound({x, 0});
    t.erase(it);
  }

  int get() { return t.find_by_order(t.size() / 2)->first; }
  void clear() {
    ti = 0;
    t.clear();
  }
};

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);

  for (int &x : a) {
    cin >> x;
  }

  multree pref;
  for (int i = 0; i < n; i++) {
    pref.insert(a[i]);
  }
  multree suf;
  bool ok = false;
  for (int j = n - 1; j >= 0; j--) {
    pref.erase(a[j]);
    suf.insert(a[j]);
    if (suf.get() == pref.get() && (suf.size() & 1) && (pref.size() & 1)) {
      ok = true;
    }
  }

  cout << (ok ? "Yes\n" : "No\n");
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int tt = 1;
#ifdef home
  cin >> tt;
#endif
  while (tt--) {
    solve();
  }
}
