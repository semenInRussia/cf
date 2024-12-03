// semenInRussia 2024
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
using namespace std;

const int N = 2e5;
int a[N];

void solve() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  map<int, int> cnt;

  for (int i = 0; i < n; i++) {
    cnt[a[i]]++;
  }

  int64_t ans = 0;
  int c = n;
  int prv = 0;
  for (auto [val, cur] : cnt) {
    // we can add
    // val * c
    if (1ll * (val - prv) * c >= k) {
      ans += k;
      break;
    }
    ans += 1ll * (val - prv) * c;
    ans += cur;
    k -= (val - prv) * c;
    prv = val;
    c -= cur;
  }

  cout << ans << '\n';
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
