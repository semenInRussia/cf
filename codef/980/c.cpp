// semenInRussia 2024
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int N = 2e5;
pair<int, int> p[N];

int count(vector<int> a) {
  int ans = 0;
  int n = int(a.size());
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      ans += a[i] > a[j];
    }
  }
  return ans;
}

bool cmp(pair<int, int> x, pair<int, int> y) {
  auto [a, b] = x;
  auto [c, d] = y;

  vector<int> abcd = {a, b, c, d};
  vector<int> cdab = {c, d, a, b};
  int s = count(abcd);
  int t = count(cdab);
  return s < t;
}

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> p[i].first >> p[i].second;
  }

  // 10, 20 > 40, 30
  sort(p, p + n, cmp);
  for (int i = 0; i < n; i++) {
    cout << p[i].first << ' ' << p[i].second << ' ';
  }
  cout << '\n';
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
