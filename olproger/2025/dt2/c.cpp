// semenInRussia 2024
#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <random>
#include <set>
#include <vector>

using namespace std;

const int N = 105;
int n;
int p[N], sz[N];
bool used[N];

int get(int i) {
  if (p[i] == i) {
    return p[i];
  }
  return p[i] = get(p[i]);
}

int join(int i, int j) {
  i = get(i);
  j = get(j);
  sz[j] += sz[i];
  return p[i] = j;
}

int qry(set<int> &a, set<int> &b) {
  if (a.empty() || b.empty()) {
    return 0;
  }

#ifdef home
  cout << "| ";
#else
  cout << "? " << a.size() << " ";
#endif

  for (int x : a) {
    cout << x + 1 << " ";
  }

#ifdef home
  cout << "| ";
#else
  cout << " " << b.size() << " ";
#endif

  for (int x : b) {
    cout << x + 1 << " ";
  }
  cout << endl;

  string t;
  cin >> t;
  return t == "YES";
}

pair<set<int>, set<int>> div(set<int> &s) {
  set<int> a, b;
  for (int x : s) {
    auto &d = a.size() < b.size() ? a : b;
    d.insert(x);
  }
  return {a, b};
}

pair<int, int> solve() {
  vector<vector<int>> v(n);
  for (int i = 0; i < n; i++) {
    v[get(i)].push_back(i);
  }

  set<int> ab[2];

  for (int j = 0; j < 8; j++) {
    ab[0].clear();
    ab[1].clear();

    for (int i = 0; i < n; i++) {
      auto &d = ab[(i >> j) & 1];
      for (int x : v[i]) {
        d.insert(x);
      }
    }

    bool ok = qry(ab[0], ab[1]);
    if (ok) {
      return solve2(ab[0], ab[1]);
    }
  }
  assert(0 && "unreach!");
  return {-1, -1};
}

pair<int, int> solve2(set<int> &a, set<int> &b) {
  if (a.empty() || b.empty()) {
    return {-1, -1};
  }

  while (a.size() > 1ull) {
    auto [c, d] = div(a);
    bool ok = qry(c, b);
    if (ok) {
      swap(a, c);
    } else {
      swap(a, d);
    }
  }

  while (b.size() > 1ull) {
    auto [c, d] = div(b);
    bool ok = qry(a, c);
    if (ok) {
      swap(b, c);
    } else {
      swap(b, d);
    }
  }

  assert(a.size() == 1ull);
  int v = *a.begin();

  assert(b.size() == 1ull);
  int u = *b.begin();

  if (v > u) {
    swap(v, u);
  }

  return {v, u};
}

int main() {
  cin >> n;

  for (int i = 0; i < n; i++) {
    p[i] = i;
    sz[i] = 1;
  }

  for (int j = 1; j < n; j++) {
    auto [v, u] = solve();
    cout << "! " << (v + 1) << " " << (u + 1) << endl;
    join(v, u);
  }
}
