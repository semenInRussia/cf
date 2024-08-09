// semenInRussia 2024
// https://cses.fi/problemset/task/1091
#include <algorithm>
#include <iostream>
using namespace std;

const int N = 2e5;
pair<int, int> p[2 * N];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    p[i] = {a, +1};
    p[n + i] = {b, -1};
  }
  sort(p, p + 2 * n);
  int cur = 0, ans = 0;
  for (int i = 0; i < 2 * n; i++) {
    cur += p[i].second;
    ans = max(ans, cur);
  }
  cout << ans;
}
