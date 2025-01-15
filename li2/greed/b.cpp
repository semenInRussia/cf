// semenInRussia 2025
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n;
  cin >> n;

  vector<int> a(n);

  for (int &x : a) {
    cin >> x;
  }

  sort(a.begin(), a.end(), [](auto x, auto y) {
    int s = x % 10 == 0;
    int t = y % 10 == 0;
    return s > t || (s == t && x < y);
  });

  int k;
  cin >> k;

  int64_t ans = 0;

  for (int x : a) {
    if (x < 10) {
      continue;
    }
    int v = ((x - 1) / 10);
    int d = min(v, k);

    ans += d + (x % 10 == 0 && k >= v);
    k -= d;
  }

  cout << ans;
}
