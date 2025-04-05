// semenInRussia 2025
#include <cstdint>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

void solve() {
  int n;
  cin >> n;

  multiset<pair<int, int>> a;

  for (int i = 0; i < n; i++) {
    int x, h;
    cin >> x >> h;
    a.emplace(h, x);
  }

  int ans = 0;

  while (!a.empty()) {
    ans++;

    auto it = prev(a.end());
    auto [hi, xi] = *it;
    a.erase(it);

    vector<pair<int, int>> del;

    for (auto [hj, xj] : a) {
      if (abs(xi - xj) <= hi - hj) {
        del.emplace_back(hj, xj);
      }
    }

    for (auto [hj, xj] : del) {
      a.erase(a.find({hj, xj}));
    }
  }

  cout << ans;
}

int main() {
  int tt = 1;
#ifdef home
  cin >> tt;
#endif

  while (tt--) {
    solve();
    cout << "\n";
  }
}
