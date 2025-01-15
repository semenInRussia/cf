// semenInRussia 2024
#include <cassert>
#include <cstdint>
#include <iostream>
#include <queue>

using namespace std;

using ll = long long;

const int N = 3005;
ll cur[N];

ll s[N];

void solve() {
  int n, m, k;
  cin >> n >> m >> k;

  ll A, B, C, T;
  cin >> A >> B >> C >> T;

  for (int i = 0; i < m; i++) {
    cin >> s[i];
    s[i]--;
  }

  ll ans = 0;

  for (int i = 0; i < m - 1; i++) {
    auto c = (T - s[i] * B) / A;

    c = min(c, s[i + 1] - s[i] - 1);
    c = max(c, 0ll);

    cur[i] = -1;

    auto op = s[i] * B;
    if (op <= T) {
      cur[i] = s[i] + c + 1;
      ans += c + 1;
    }
  }

  ans += B * (n - 1) <= T;

  for (int z = 0; z < k - m; z++) {
    pair<int, int> bst = {0, 0};

    for (int i = 0; i < m - 1; i++) {
      auto k = cur[i];
      auto op = (k - s[i]) * C + s[i] * B;

      if (op > T || k == -1 || k == s[i + 1]) {
        continue;
      }

      auto j = (T - s[i] * B - (k - s[i]) * C) / A;
      j = min(j, s[i + 1] - k - 1);
      j = max(j, 0ll);

      bst = max(bst, {j + 1, i});
    }

    auto [v, i] = bst;

    cur[i] += v;
    ans += v;
  }

  cout << max(0ll, ans - 1);
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int tt = 1;
#ifdef home
  cin >> tt;
#endif
  while (tt--) {
    solve();
    cout << "\n";
  }
}
