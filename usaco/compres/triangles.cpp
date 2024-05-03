// Copyright 2024 semenInRussia

#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

using ll = long long;
const ll MOD = 1e9 + 7;

// for every (x, y)
//
// x,y
// (x1, y1); (x2, y2)
// [x1=x]: y1>y
// [y2=y]: x2>x
//
// (x2-x)*(y2-y)
// + (x2-x)*(y2-y)

inline int dist(set<int> &s, int x) { return distance(s.begin(), s.find(x)); }

int main() {
  ifstream cin("triangles.in");
  ofstream cout("triangles.out");

  int n;
  cin >> n;

  using pii = pair<int, int>;
  vector<pii> points(n);
  set<int> xs, ys;
  for (auto &p : points) {
    cin >> p.first >> p.second;
    xs.insert(p.first), ys.insert(p.second);
  }

  vector<set<int>> xf(xs.size()), yf(ys.size());

  for (auto p : points) {
    xf[dist(xs, p.first)].insert(p.second);
    yf[dist(ys, p.second)].insert(p.first);
  }

  ll ans = 0;
  for (auto p : points) {
    // sum < x, < y
    ll a = 0, b = 0;
    for (auto y : xf[p.first])
      if (y < p.second)
        a = (a + abs(p.second - y + 1)) % MOD;
    for (auto x : yf[p.second])
      if (x < p.first)
        b = (b + abs(p.first - x + 1)) % MOD;
    ans += a * b;

    // >x, <y
    a = 0, b = 0;
    for (auto y : xf[p.first])
      if (y < p.second)
        a = (a + abs(p.second - y + 1)) % MOD;
    for (auto x : yf[p.second])
      if (x > p.first)
        b = (b + abs(p.first - x + 1)) % MOD;
    ans += a * b;
    // >x, <y
    a = 0, b = 0;
    for (auto y : xf[p.first])
      if (y > p.second)
        a = (a + abs(p.second - y + 1)) % MOD;
    for (auto x : yf[p.second])
      if (x < p.first)
        b = (b + abs(p.first - x + 1)) % MOD;
    ans += a * b;
    // >x, >y
    a = 0, b = 0;
    for (auto y : xf[p.first])
      if (y > p.second)
        a = (a + abs(p.second - y + 1)) % MOD;
    for (auto x : yf[p.second])
      if (x > p.first)
        b = (b + abs(p.first - x + 1)) % MOD;
    ans += a * b;
  }

  cout << ans << endl;
}
