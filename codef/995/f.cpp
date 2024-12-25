// semenInRussia 2024
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
  int n, m, q;
  cin >> n >> m >> q;

  vector<pair<int, int>> s;

  s.push_back({m, m});

  for (int i = 0; i < q; i++) {
    int x;
    cin >> x;

    vector<pair<int, int>> v;

    for (auto [l, r] : s) {
      if (l <= x && x <= r) {
        v.push_back({1, 1});
        v.push_back({n, n});
        if (r - l >= 1) {
          v.push_back({l, r});
        }
      } else if (x < l) {
        v.push_back({max(1, l - 1), r});
      } else if (x > r) {
        v.push_back({l, min(r + 1, n)});
      }
    }

    s = v;

    sort(s.begin(), s.end());

    vector<pair<int, int>> d = {s[0]};

    for (int j = 1; j < int(s.size()); j++) {
      auto [l1, r1] = d.back();
      auto [l2, r2] = s[j];

      auto l = max(l1, l2);
      auto r = min(r1, r2);

      if (r - l >= 0) {
        d.pop_back();
        d.push_back({min(l1, l2), max(r1, r2)});
      } else {
        d.push_back({l2, r2});
      }
    }

    s = d;

    int ans = 0;
    for (auto [l, r] : s) {
      ans += max(0, r - l + 1);
    }

    cout << ans << " ";
  }
  cout << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
