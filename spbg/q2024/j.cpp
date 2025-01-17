
// semenInRussia 2024
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

void solve1() {
  int n;
  cin >> n;

  int k = min(1000, n);

  cout << k << " " << k << "\n";

  vector<int> p(n);

  for (int i = 0; i < n; i++) {
    p[i] = n - i;
  }

  // std::random_device rd;
  std::mt19937 g(100);
  shuffle(p.begin() + 1, p.end(), g);

  for (int i = 0; i < k; i++) {
    cout << p[i] << " ";
  }
}

void solve2() {
  int k;
  cin >> k >> k;

  vector<vector<int>> rows(k);

  for (auto &row : rows) {
    row.resize(k);
    for (int &x : row) {
      cin >> x;
      x--;
    }
  }

  int n = rows.front()[0] + 1;

  auto b = rows;

  for (auto &r : b) {
    sort(r.begin(), r.end());
  }

  auto can = [&](int i, int j) {
    return binary_search(b[j].begin(), b[j].end(), rows[i].back());
  };

  vector<bool> used(n, false);
  vector<int> order;
  order.reserve(k);

  used[0] = 1;
  order.push_back(0);

  for (int i = 0; i < k - 1; i++) {
    for (int j = 0; j < k; j++) {
      if (!used[j] && can(order.back(), j)) {
        order.push_back(j);
        used[j] = 1;
        break;
      }
    }
  }

  used.assign(k, false);

  vector<int> ans;
  ans.reserve(n);

  for (int i : order) {
    for (int x : rows[i]) {
      if (used[x]) {
        continue;
      }
      used[x] = true;
      ans.push_back(x);
    }
  }

  for (int x = 0; x < n; x++) {
    if (!used[x]) {
      ans.push_back(x);
    }
  }

  int r = find(ans.begin(), ans.end(), 0) - ans.begin();
  for (int i = r; i < n; i++) {
    cout << (ans[i] + 1) << ' ';
  }
  for (int i = 0; i < r; i++) {
    cout << (ans[i] + 1) << ' ';
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  string t;
  cin >> t;
  if (t == "ask") {
    solve1();
  } else {
    solve2();
  }
}
