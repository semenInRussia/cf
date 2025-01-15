// https://www.acwing.com/problem/content/834/
#include <cstdint>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

const int inf = 1e9;

pair<int, int> find(set<pair<int, int>> &s, int x) {
  return *prev(s.upper_bound({x, +inf}));
}

void add(set<pair<int, int>> &s, int i) {
  if (s.empty()) {
    s.insert({i, i});
    return;
  }

  pair<int, int> v = {-1, -1}; // new segment

  // find [l; r] l > i
  auto it = s.upper_bound({i, 0});
  if (it != s.end() && i + 1 == it->first) {
    auto [l, r] = *it;
    s.erase(it);
    s.insert({i, r});
    v = {i, r};
  }

  // find [l; r] l < i
  it = prev(s.upper_bound({i, 0}));
  if (v.first == -1 && it != s.end() && i == it->second + 1) {
    auto [l, r] = *it;
    s.erase(it);
    s.insert({l, i});
    v = {l, i};
  }

  // if we didn't add anything
  if (v.first == -1) {
    v = {i, i};
    s.insert(v);
  }

  // clean up
  it = s.find(v);

  if (prev(it) != s.end() && prev(it)->second + 1 == v.first) {
    pair<int, int> v1 = {prev(it)->first, v.second};
    s.erase(prev(it));
    s.erase(v);
    s.insert(v1);
  }

  if (next(it) != s.end() && v.second + 1 == next(it)->first) {
    pair<int, int> v1 = {v.first, next(it)->second};
    s.erase(next(it));
    s.erase(v);
    s.insert(v1);
  }
}

void solve() {
  int n, R, C, r, c;
  cin >> n >> R >> C >> r >> c;

  string a;
  cin >> a;

  vector<set<pair<int, int>>> col(C), row(R);

  int i = r - 1;
  int j = c - 1;

  add(col[j], i);
  add(row[i], j);

  for (char c : a) {
    if (c == 'S') {
      auto [l, r] = find(col[j], i);
      i = r + 1;
    }
    if (c == 'N') {
      auto [l, r] = find(col[j], i);
      i = l - 1;
    }
    if (c == 'E') {
      auto [l, r] = find(row[i], j);
      j = r + 1;
    }
    if (c == 'W') {
      auto [l, r] = find(row[i], j);
      j = l - 1;
    }

    add(col[j], i);
    add(row[i], j);
  }

  cout << i + 1 << " " << j + 1 << "\n";
}

int main() {
  int T;
  cin >> T;
  for (int x = 1; x <= T; x++) {
    cout << "Case #" << x << ": ";
    solve();
  }
}
