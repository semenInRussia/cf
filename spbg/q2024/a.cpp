// semenInRussia 2024
#include <algorithm>
#include <iostream>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx2")

int main() {
  // cin.tie(nullptr)->sync_with_stdio(0);

  int64_t a, b, c, t;
  cin >> a >> b >> c >> t;
  pair<int64_t, int> ar[3] = {{a, 0}, {b, 1}, {c, 2}};

  for (int64_t round = 0; round < t;) {
    sort(ar, ar + 3);
    int64_t &x = ar[0].first;
    int64_t &y = ar[1].first;
    int64_t z = ar[2].first;

    if (x == y) {
      break;
    }

    int64_t d = y - x;
    int64_t i = (z - y) / d - 1;

    i = max(i, 0ll);
    i = min(i, t - round - 1);
    round += i + 1;

    x = (i + 1) * d + y;
    y = i * d + y;

    if (i & 1) {
      swap(y, x);
    }
  }

  sort(ar, ar + 3, [](auto a, auto b) { return a.second < b.second; });
  for (int i = 0; i < 3; i++) {
    cout << ar[i].first << ' ';
  }
}
