// Copyright 2024 semenInRussia

#include <algorithm>
#include <atomic>
#include <fstream>
#include <vector>

using ll = long long;

using namespace std;

int mod;
bool by_mod(int a, int b) { return a % mod > b % mod; }

int main() {
  ifstream cin("berries.in");
  ofstream cout("berries.out");

  int n, k;
  cin >> n >> k;

  vector<int> b(n);
  int mx = 0;
  for (auto &x : b) {
    cin >> x;
    mx = max(mx, x);
  }

  ll ans = 0;
  for (int m = 1; m <= mx; m++) {
    int full = 0;
    for (int i = 0; i < n; i++)
      full += b[i] / m;

    if (full >= k) {
      ans = max(ans, 1ll * (k / 2) * m);
      continue;
    }
    if (full < k / 2)
      break;

    mod = m;
    sort(b.begin(), b.end(), by_mod);
    ll cur = (full - k / 2) * m;
    // alread full - k/2
    for (int i = 0; i + full < k; i++)
      cur += b[i] % m;
    ans = max(cur, ans);
  }

  cout << ans << endl;
}
