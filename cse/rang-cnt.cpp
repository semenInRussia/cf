// semenInRussia 2024
// https://cses.fi/problemset/task/2169
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

map<pair<int, int>, int> ans1, ans2;

const int N = 2e5;
pair<int, int> p[N], _p[N];
int id[N], bs[N], t[N + 1];

int qry(int r) {
  int ans = 0;
  for (; r > 0; r -= r & -r)
    ans += t[r];
  return ans;
}

void add(int i, int v) {
  for (; i <= N; i += i & -i)
    t[i] += v;
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> p[i].first >> p[i].second;
    _p[i] = p[i];
    bs[i] = p[i].second;
  }

  sort(p, p + n, [](auto x, auto y) {
    return x.first < y.first || (x.first == y.first && x.second > y.second);
  });

  sort(bs, bs + n);
  int u = unique(bs, bs + n) - bs;
  for (int i = 0; i < n; i++) {
    id[i] = lower_bound(bs, bs + u, p[i].second) - bs;
  }

  // count c,d: c >= a, d <= b
  for (int i = n - 1; i >= 0; i--) {
    int b = id[i];
    ans1[p[i]] = qry(b + 1);
    add(b + 1, 1);
  }
  fill(t, t + u, 0);

  // count c,d: c <= a, d >= b
  for (int i = 0; i < n; i++) {
    int b = id[i];
    ans2[p[i]] = i - qry(b);
    add(b + 1, 1);
  }

  swap(_p, p);
  for (int i = 0; i < n; i++) {
    cout << ans1[p[i]] << ' ';
  }
  cout << '\n';
  for (int i = 0; i < n; i++) {
    cout << ans2[p[i]] << ' ';
  }
}
