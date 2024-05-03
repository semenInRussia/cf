#include <bits/stdc++.h>
using namespace std;

struct point {
  int x, y;
};

int count(vector<point> &cows, int a, int b) {
  int ans[4] = {0, 0, 0, 0};
  for (auto cow : cows)
    ans[(cow.x < a) * 2 + (cow.y < b)]++;
  return *max_element(ans, ans + 4);
}

int main() {
  ifstream cin("balancing.in");
  ofstream cout("balancing.out");

  int n, b;
  cin >> n >> b;

  vector<point> cows(n);
  for (auto &cow : cows)
    cin >> cow.x >> cow.y;

  unordered_set<int> xs, ys;
  for (auto cow : cows)
    xs.insert(cow.x), ys.insert(cow.y);

  int ans = b;
  for (auto x : xs)
    for (auto y : ys)
      ans = min(ans, count(cows, x + 1, y + 1));

  cout << ans;
}
