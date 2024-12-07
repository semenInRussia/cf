// semenInRussia 2024
#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  for (auto &x : a) {
    cin >> x;
  }

  int pref = 0;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (pref + a[i].size() <= m) {
      pref += a[i].size();
      ans++;
    } else {
      break;
    }
  }
  cout << ans << "\n";
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
