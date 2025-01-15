// semenInRussia 2025
#include <cstdint>
#include <iostream>
#include <set>
#include <vector>

// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,fma,bmi2,tune=native")

using namespace std;

const int inf = 1e9 + 100;

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n, m, q;
  cin >> n >> m >> q;

  vector<set<int>> row(n), col(m);

  auto extend = [](set<int> &s, int n) {
    if (s.empty()) {
      s.insert(-inf);
      s.insert(+inf);
      for (int i = 0; i < n; i++) {
        s.insert(i);
      }
    }
  };

  auto add = [](set<pair<int, int>> &s, int j) {
    if (s.empty()) {
      s.insert({j, j});
      return;
    }
    auto it = s.lower_bound({j, -inf});
    auto jt = prev(s.lower_bound({j, -inf}));

    if (it != s.end() && jt->second + 1 == j && j + 1 == it->first) {
      auto [l, r] = *it;
      auto [lp, rp] = *jt;
      s.erase(it);
      s.erase(jt);
      s.insert({lp, rp});
    } else if (it != s.end() && j + 1 == it->first) {
      auto [l, r] = *it;
        }
  };

  while (q--) {
    char t;
    int i, j;
    cin >> t >> i >> j;
    i--, j--;

    extend(row[i], m);
    extend(col[i], n);

    if (t == 'c') {
      row[i].erase(j);
      col[j].erase(i);
      continue;
    }

    int i2 = i;
    int j2 = j;

    if (t == 'd') {
      i2 = *col[j].upper_bound(i);
    }
    if (t == 'u') {
      i2 = *prev(col[j].lower_bound(i));
    }
    if (t == 'l') {
      j2 = *prev(row[i].lower_bound(j));
    }
    if (t == 'r') {
      j2 = *row[i].upper_bound(j);
    }

    if (abs(i2) == +inf || abs(j2) == +inf) {
      cout << "-1\n";
    } else {
      cout << i2 + 1 << " " << j2 + 1 << "\n";
    }
  }
}
