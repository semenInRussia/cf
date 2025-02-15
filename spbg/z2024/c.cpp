// semenInRussia 2025
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

const int64_t inf = 1e18;
const int N = 105;
vector<pair<int64_t, int64_t>> f[N];
int a[N];

template <typename T> T &setmax(T &v, T op) { return v = max(v, op); }

#pragma GCC optimize("O3,unroll-loops")

void clean(vector<pair<int64_t, int64_t>> &row) {
  int j = 0;
  sort(row.begin(), row.end());
  for (int i = 0; i < int(row.size()); i++) {
    if (row[i].first != row[j].first) {
      j++;
    }
    row[j] = row[i];
  }
  row.resize(j + 1);
  j = 0;
  for (int i = 0; i < int(row.size()); i++) {
    if (row[i].second != row[j].second) {
      j++;
    }
    row[j] = row[i];
  }
  row.resize(j + 1);
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  f[0] = {{1, 1}};

  for (int i = 0; i < n; i++) {
    clean(f[i]);
    for (auto [j, v] : f[i]) {
      auto k = v / a[i];
      f[i + 1].push_back({j + k, v + j + k - k * a[i]});
      f[i + 1].push_back({j, v + j});
    }
  }

  int64_t ans = 0;

  for (auto [j, v] : f[n]) {
    ans = max(ans, v - j);
  }

  cout << ans;
}
