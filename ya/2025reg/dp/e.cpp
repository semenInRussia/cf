// semenInRussia 2025
#include <cstdint>
#include <iostream>
#include <map>

using namespace std;

const int mod = 1e9 + 7;

const int N = 3005;
int64_t a[N], pref[N];

int f[N][N];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < n; i++) {
    pref[i + 1] = pref[i] + a[i];
  }

  // amount of a [0..i] cover with j blocks

  for (int i = 0; i < n; i++) {
    f[i][1] = 1;
  }

  for (int j = 2; j <= n; j++) {
    // f[i][j] += f[i' < i][j - 1] if pref[i':i]%j=0
    map<int, int64_t> mp;
    for (int i = 0; i < n; i++) {
      int cur = pref[i + 1] % j;
      f[i][j] = mp[cur];
      (mp[cur] += f[i][j - 1]) %= mod;
    }
  }

  int64_t ans = 0;
  for (int j = 1; j <= n; j++) {
    (ans += f[n - 1][j]) %= mod;
  }

  cout << ans << "\n";
}
