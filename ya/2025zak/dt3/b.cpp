// semenInRussia 2025
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

// - sort by second
// - go by this order
// - for every who s[j] <= e[i], add the first and final edge
// - we get tree (no cycles)
// - how to get answer?
// - we go to parent, while not go e[i] <= e[a]

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n, q;
  cin >> n >> q;

  vector<pair<int, int>> e(n), _e;

  auto cmp = [](auto a, auto b) {
    return a.second < b.second || (a.second == b.second && a.first < b.first);
  };

  for (auto &[l, r] : e) {
    cin >> l >> r;
  }

  _e = e;

  sort(e.begin(), e.end());
  e.resize(unique(e.begin(), e.end()) - e.begin());
  n = (int)e.size();

  sort(e.begin(), e.end(), cmp);

  set<pair<pair<int, int>, int>> suf;
  for (int i = 0; i < n; i++) {
    suf.insert({e[i], i});
  }

  vector<int> par(n, -1);

  for (int i = 0; i < n; i++) {
    auto it = suf.find({e[i], i});
    if (it != suf.end()) {
      suf.erase(it);
    }
    vector<pair<pair<int, int>, int>> del;
    for (auto [lr, j] : suf) {
      if (lr.first <= e[i].second && par[j] == -1) {
        par[j] = i;
        del.push_back({lr, j});
      }
    }
    for (auto el : del) {
      suf.erase(el);
    }
  }

  while (q--) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    a = lower_bound(e.begin(), e.end(), _e[a], cmp) - e.begin();
    b = lower_bound(e.begin(), e.end(), _e[b], cmp) - e.begin();
    if (e[b].second < e[a].second) {
      cout << "impossible\n";
      continue;
    }
    int ans = 0;
    while (b != -1 && e[b].second > e[a].second) {
      b = par[b];
      ++ans;
    }
    if (b == -1) {
      cout << "impossible\n";
    } else {
      cout << ans << "\n";
    }
  }
}
