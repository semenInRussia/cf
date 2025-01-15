// semenInRussia 2024
#include <cstdint>
#include <iostream>

using namespace std;

int64_t don(int64_t v, int64_t sz) {
  int64_t ans = 1;
  while (sz != v && sz) {
    sz = (sz - 1) / 2;
    ans *= 2;
  }
  return ans - 1;
}

pair<int64_t, int64_t> solv(int64_t i, int64_t sz) {
  if (i * 2 == sz || i * 2 + 1 == sz || (i + 1) * 2 == sz) {
    return {sz, 1};
  }

  auto mid = sz / 2;
  auto szp = (sz - 1) / 2;

  if (i < mid) {
    auto [v, c] = solv(i, szp);
    return {v, c + 1 + don(v, szp)};
  }

  auto [v, c] = solv(i - (sz / 2) - 1, szp);
  return {v, c + 1 + don(v, sz)};
}

int main() {
  int64_t n;
  int q;
  cin >> n >> q;

  while (q--) {
    int64_t j;
    cin >> j;
    if (j == 1 || j == n) {
      cout << "1 ";
      continue;
    }

    cout << solv(j - 2, n - 2).second + 1 << " ";
  }
}
