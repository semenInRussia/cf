// semenInRussia 2024
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
using ll = long long;

#pragma GCC optimize("Ofast,unroll-loops")

const int N = 3010, M = 200;
const ll inf = 1e18 + 5;
int b[M], a[N];

map<tuple<int, bool, int, int>, ll> memo;

int m;
ll f(int j, bool take, int big, int small) {
  if ((big + small) > m || j < 0 || big < 0 || small < 0) {
    return 0;
  }

  if (j == 0) {
    if (take) {
      ll ans = a[j];
      if (big && small) {
        ans = max(ans, ll(max(b[small], a[j]) + b[m - big]));
      } else if (big) {
        ans = max(ans, 1ll * b[m - big]);
      } else if (small) {
        ans = max(ans, 1ll * b[small]);
      }
      return ans;
    }
  }

  tuple<int, bool, int, int> key = {j, take, big, small};

  if (memo.count(key)) {
    return memo[key];
  }

  ll &ans = memo[key];

  if (take) {
    ans = max({
        f(j - 1, 1, big - 1, small) + b[m - big],
        f(j - 1, 1, big, small - 1) + a[j],
        f(j - 1, 0, big, small) + a[j],
    });
    return ans;
  }

  ans = max({
      f(j - 1, 1, big, small),
      f(j - 1, 0, big - 1, small) + b[m - big],
      f(j - 1, 0, big, small - 1) + a[j],
  });

  return ans;
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }

  sort(b, b + m);

  ll ans = -inf;
  for (int s = 0; s <= m; s++) {
    for (int bg = 0; bg + s <= m; bg++) {
      ans = max(ans, f(n - 1, 0, bg, s));
      ans = max(ans, f(n - 1, 1, bg, s));
    }
  }
  cout << ans;
}
