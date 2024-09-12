// semenInRussia 2024
#include <cstdint>
#include <iostream>
using namespace std;
using ll = long long;

void solve() {
  string a, b;
  cin >> a >> b;
  int n = (int)a.size();
  int m = (int)b.size();
  int ans = n + m;
  for (int st = 0; st < m; st++) {
    int cur = n + m;
    int j = st;
    for (int i = 0; i < n; i++)
      if (j < m && a[i] == b[j])
        j++, cur--;
    ans = min(ans, cur);
  }
  cout << ans << '\n';
}

int main() {
  int tt;
  cin >> tt;
  while (tt--)
    solve();
}
