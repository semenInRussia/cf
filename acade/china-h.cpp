int main() {
  int n;
  cin >> n;

  set<pair<int, int>> s;
  // s.insert({0, 0});

  for (auto [l, r] : s) {
    cout << "[" << l << "; " << r << "], ";
  }

  for (int i = 0; i < n; i++) {
    int j;
    cin >> j;
    add(s, j);
    cout << "add " << j << "\n";
    for (auto [l, r] : s) {
      cout << "[" << l << "; " << r << "], ";
    }
    cout << "\n";
  }
}

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;

  vector<int> c(n), p;

  for (int i = 0; i < n; i++) {
    c[i] = i;
  }

  // generate p_n
  do {
    for (int x : c) {
      p.push_back(x);
    }
  } while (next_permutation(c.begin(), c.end()));

  c.resize(m);
  for (int i = 0; i < m; i++) {
    c[i] = i;
  }

  const int mod = 1e9 + 7;

  int ans = 0;

  do {
    for (int i = 0; i + m <= (int)p.size(); i++) {
      ans += equal(c.begin(), c.end(), p.begin() + i, p.begin() + i + m);
      ans %= mod;
    }
  } while (next_permutation(c.begin(), c.end()));

  cout << ans << "\n";
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
