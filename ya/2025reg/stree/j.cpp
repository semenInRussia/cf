// semenInRussia 2025
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

struct tree {
  vector<int64_t> t;

  tree(int n) { t.resize(n + 1); }

  int64_t sum(int j) {
    int64_t s = 0;
    for (; j > 0; j -= j & -j) {
      s += t[j];
    }
    return s;
  }

  void add(int j, int v) {
    j++;
    for (; j < int(t.size()); j += j & -j) {
      t[j] += v;
    }
  }
};

int main() {
  freopen("ds.in", "r", stdin);
  freopen("ds.out", "w", stdout);
  vector<pair<int, int>> p;

  char c;
  int x;

  while (cin >> c >> x) {
    p.emplace_back(c == '?', x);
  }

  vector<int> b;

  for (auto [t, x] : p) {
    b.push_back(x);
  }

  sort(b.begin(), b.end());
  b.resize(unique(b.begin(), b.end()) - b.begin());

  tree t(b.size());

  for (auto [ch, x] : p) {
    // cout << ch << " " << x << "\n";
    int j = lower_bound(b.begin(), b.end(), x) - b.begin();
    if (ch) {
      cout << t.sum(j + 1) << "\n";
    } else {
      t.add(j, +x);
    }
  }
}
