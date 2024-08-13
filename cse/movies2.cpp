// semenInRussia 2024
// https://cses.fi/problemset/task/1632
#include <iostream>
#include <set>
using namespace std;

multiset<int> s;
const int N = 2e5;
pair<int, int> p[N];

int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> p[i].first >> p[i].second;
  }
  sort(p, p + n, [](auto a, auto b) { return a.second < b.second; });

  for (int i = 0; i < k; i++)
    s.insert(0);

  int ans = 0;
  for (int i = 0; i < n; i++) {
    auto [a, b] = p[i];
    auto it = s.upper_bound(a);
    if (it == s.begin())
      continue;

    s.erase(prev(it));
    s.insert(b);
    ans++;
  }
  cout << ans;
}
