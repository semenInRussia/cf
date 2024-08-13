// semenInRussia 2024
// https://cses.fi/problemset/task/1630
#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e5;
pii p[N];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> p[i].first >> p[i].second;

  sort(p, p + n);
  ll t = 0, ans = 0;
  for (int i = 0; i < n; i++) {
    t += p[i].first;
    ans += p[i].second - t;
  }
  cout << ans;
}
