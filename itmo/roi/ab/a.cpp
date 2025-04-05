// semenInRussia 2025
#include <cstdint>
#include <iostream>
#include <map>

using namespace std;

int main() {
  int n, k, p;
  cin >> n >> k >> p;

  map<int, int> row, col, cnt1, cnt2;
  cnt1[0] = n;
  cnt2[0] = n;

  // int64_t ans = 0;
  // int z = 0; // count zeroes

  auto add = [&](int r, int c, int x) {
    --cnt1[row[r]];
    row[r] ^= x;
    ++cnt1[row[r]];

    --cnt2[col[c]];
    col[c] ^= x;
    ++cnt2[col[c]];
  };

  map<pair<int, int>, int> val;

  for (int i = 0; i < k; i++) {
    int r, c, x;
    cin >> r >> c >> x;
    add(r, c, x);
    val[{r, c}] = x;
  }

  for (int i = 0; i < p; i++) {
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    add(r1, c1, val[{r1, c1}]);
    add(r2, c2, val[{r1, c1}]);

    val[{r2, c2}] = val[{r1, c1}];
    val[{r1, c1}] = 0;

    int64_t ans = 1ll * n * n;
    for (auto [k, v] : cnt1) {
      ans -= 1ll * v * cnt2[k];
    }
    cout << ans << "\n";
  }
}
