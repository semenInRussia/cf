// semenInRussia 2025
#include <cstdint>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);

  for (int &x : a) {
    cin >> x;
  }

  vector<int> b(n + 1);

  int m;
  cin >> m;

  vector<vector<int>> op(n);

  for (int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;
    l--;
    op[l].push_back(r);
    b[l]++;
    b[r]--;
  }

  for (int i = 1; i < n; i++) {
    b[i] += b[i - 1];
  }

  vector<int> ad(n + 1);

  multiset<int> s; // right bounds

  int pref = 0;
  int ans = 0;

  for (int i = 0; i < n; i++) {
    pref += ad[i];
    int d = b[i] - a[i] - pref;
    for (int r : op[i]) {
      s.insert(r);
    }
    if (d < 0) {
      continue;
    }
    for (int i = 0; i < d; i++) {
      auto it = --s.end();
      int r = *it;
      ad[r]--;
      pref++;
      s.erase(it);
      ans++;
    }
  }

  cout << ans;
}
