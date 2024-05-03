// Copyright 2024 semenInRussia

// sqr = (max(x) - min(x)) * (max(y) - min(y))

// find the best cow to remove.  it can be either:
// - with max(x)
// - with max(y)
// - with min(x)
// - with min(y)

#include <algorithm>
#include <cstdint>
#include <fstream>
#include <set>
#include <vector>

using namespace std;

using Cow = pair<int, int>;
multiset<Cow> xs, ys;

int sqr_without(int del_id) {
  auto check = [del_id](Cow c) { return c.second != del_id; };
  int minx = find_if(xs.begin(), xs.end(), check)->first;
  int maxx = find_if(xs.rbegin(), xs.rend(), check)->first;
  int miny = find_if(ys.begin(), ys.end(), check)->first;
  int maxy = find_if(ys.rbegin(), ys.rend(), check)->first;
  return (maxx - minx) * (maxy - miny);
}

int solve(int round, int cow_id = -1) {
  int cow_x, cow_y;

  if (round > 0) {
    for (auto [x, id] : xs)
      cow_x = (id == cow_id) ? x : cow_x;
    for (auto [y, id] : ys)
      cow_y = (id == cow_id) ? y : cow_y;
    xs.erase({cow_x, cow_id});
    ys.erase({cow_y, cow_id});
  }

  if (round == 3) {
    int ans = sqr_without(-1);
    xs.insert({cow_x, cow_id});
    ys.insert({cow_y, cow_id});
    return ans;
  }

  vector<int> ids;
  for (auto arr : {xs, ys}) {
    ids.push_back(arr.begin()->second);
    ids.push_back(arr.rbegin()->second);
  }

  int ans = INT32_MAX;
  for (int id : ids) {
    ans = min(solve(round + 1, id), ans);
  }

  if (round > 0) {
    xs.insert({cow_x, cow_id});
    ys.insert({cow_y, cow_id});
  }

  return ans;
}

int main() {
  ifstream cin("reduce.in");
  ofstream cout("reduce.out");

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    xs.insert({x, xs.size()});
    ys.insert({y, ys.size()});
  }

  if (n == 3) {
    cout << 0;
    return 0;
  }

  cout << solve(0);
}
