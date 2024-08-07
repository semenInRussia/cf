// semenInRussia 2024
#include <iostream>
using namespace std;
using ll = long long;

int cnt[4];
void solve() {
  fill(cnt, cnt + 4, 0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  for (auto ch : s)
    if (ch != '?')
      cnt[ch - 'A']++;

  int ans = 0;
  for (int i = 0; i < 4; i++)
    ans += min(n, cnt[i]);
  cout << ans << '\n';
}

int main() {
  int tt;
  cin >> tt;
  while (tt--)
    solve();
}
