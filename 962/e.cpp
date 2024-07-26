// semenInRussia 2024
#include <iostream>
#include <map>
#include <vector>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

const int N = 2e5 + 1;
int b[N];
map<int, vector<int>> m;
void solve() {
  string s;
  cin >> s;
  int n = (int)s.size();
  for (int i = 0; i < n; i++)
    b[i + 1] = b[i] + (s[i] == '1');
  m.clear();
  ll ans = 0;
  for (int r = 0; r <= n; r++)
    m[2 * b[r] - r].push_back(r);

  for (auto &[_, row] : m) {
    ll pref = 0;
    for (int i = 0; i < (int)row.size(); i++) {
      ans = (ans + pref * (1 + n - row[i])) % mod;
      pref += 1 + row[i];
    }
  }

  cout << ans << '\n';
}

int main() {
  int tt;
  cin >> tt;
  while (tt--)
    solve();
}
