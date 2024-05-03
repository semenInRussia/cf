// Copyright 2024 semenInRussia

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using ull = unsigned long long;
using pii = pair<int, int>;
const ull mod = ull(1e9 + 7);

pii operator+(pii a, pii b) {
  int m = (a.second + b.second) / mod;
  return {a.first + b.first + m, (a.second + b.second) % mod};
}

void f(vector<pii> &a) {
  using typ = pair<pii, pii>;
  priority_queue<typ, vector<typ>, greater<typ>> q;
  int n = (int)a.size();

  for (int i = 0; i + 1 < n; i++)
    q.push({(a[i] + a[i + 1]), {i, i + 1}});

  vector<pii> ans;
  while ((int)ans.size() < n - 1) {
    typ cur = q.top(); // minimum pair (i, j) by a[i] + a[j]
    q.pop();
    ans.push_back(cur.first);
    // auto [i, j] = cur.second;
    int i = cur.second.first, j = cur.second.second;
    if (j + 1 < n)
      q.push({(a[i] + a[j + 1]), {i, j + 1}});
  }
  a = std::move(ans);
}

int main() {
  int n;
  cin >> n;
  vector<pii> a(n, {0, 0});
  for (auto &x : a)
    cin >> x.second;

  sort(a.begin(), a.end());
  while ((int)a.size() > 1)
    f(a);

  cout << a.front().second << endl;
}
