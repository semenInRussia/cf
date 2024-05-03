// Copyright 2024 semenInRussia

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;
using uset = unordered_set<size_t>;

enum Direction {
  Forward,
  Back,
};

Direction query(vector<uset> &g, size_t u, size_t v) {
  if (g[u].count(v)) {
    return Forward;
  } else if (g[v].count(u)) {
    return Back;
  }

  cout << "? " << u << ' ' << v << endl;
  string ans;
  cin >> ans;
  if (ans == "forward") {
    return Forward;
  } else {
    return Back;
  }
}

void tg4() {
  size_t n = 0;
  cin >> n;
}

void test_case(size_t tg) {

  if (tg == 4) {
    tg4();
    return;
  }

  // tg is number of Test Group
  size_t n;
  cin >> n;

  vector<uset> g(n + 1);
  int found = -1;

  for (size_t u = 1; u < n + 1; u++) {
    for (size_t v = 1; v < n + 1; v++) {
      if (v == u) {
        continue;
      }

      if (g[u].size() > 1) {
        break;
      }

      auto dir = query(g, u, v);
      if (dir == Forward) {
        g[u].insert(v);
      } else {
        g[v].insert(u);
      }
    }

    if (g[u].size() <= 1) {
      found = u;
      break;
    }
  }

  cout << "! " << found << endl;
  cout.flush();

  string _verdict;
  cin >> _verdict;
}

int main() {
  int tg, t;
  cin >> tg >> t;

  while (t--) {
    test_case(tg);
  }

  return 0;
}
