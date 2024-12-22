// semenInRussia 2024
#include <cstdint>
#include <iostream>
#include <map>
using namespace std;

const int N = 3e5;
int a[N];

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n, b;
  cin >> n >> b;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  map<int, pair<int, int>> cnt;

  int64_t ans = 0;
  int64_t ad = 0;

  const int B = (1 << b) - 1;

  for (int i = 0; i < n; i++) {
    int x = a[i];

    if (x == B) {
      ans += ad;
    }

    int v = min(x, B ^ x);
    auto [s, t] = cnt[v];

    if (v == x) {
      cnt[v] = {s + 1, t};
      ad += t;
    } else {
      cnt[v] = {s, t + 1};
      ad += s;
    }
  }

  cout << ans;
}
