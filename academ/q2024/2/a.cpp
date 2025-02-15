// semenInRussia 2025
#include <cstdint>
#include <iostream>

using namespace std;

const int N = 5000;
int t[N];

void solve() {
  int n, m;
  cin >> n >> m;

  int cur = 0;
  int ans = 0;

  for (int i = 0; i < n; i++) {
    cin >> t[i];
    cur += t[i];
    cur %= m;
    if (cur == 0) {
      ans++;
    }
  }

  cout << ans;
}

int main() {
  int tt = 1;
#ifdef home
  cin >> tt;
#endif

  while (tt--) {
    solve();
    cout << "\n";
  }
}
