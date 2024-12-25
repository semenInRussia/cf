// semenInRussia 2024
#include <cstdint>
#include <iostream>
#include <numeric>

using namespace std;

void solve() {
  int64_t l, r, G;
  cin >> l >> r >> G;

  l = (l + G - 1) / G;
  r = r / G;

  using T = pair<int64_t, pair<int64_t, int64_t>>;
  T ans = {-1, {-1, -1}};

  for (auto i = l; i <= r && r - i + 1 > ans.first; i++) {
    for (auto j = r; j >= 0 && j - i + 1 > ans.first; j--) {
      if (gcd(i, j) == 1) {
        T op = {j - i, {-i, j}};
        ans = max(ans, op);
        break;
      }
    }
  }

  auto [a, b] = ans.second;

  if (ans.first != -1) {
    a *= -G;
    b *= G;
  }

  cout << a << ' ' << b << '\n';
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
