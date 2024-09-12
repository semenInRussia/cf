// semenInRussia 2024

#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;

int cnt[26];
void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < 26; i++)
    cnt[i] = 0;
  for (int i = 0; i < n; i++) {
    char ch;
    cin >> ch;
    // cout << ch << '\n';
    // cout << (ch - 'a') << '\n';
    cnt[ch - 'A']++;
  }
  int ans = 0;
  for (int i = 0; i < 7; i++)
    ans += max(m - cnt[i], 0);
  cout << ans << '\n';
}

int main() {
  int tt;
  cin >> tt;
  while (tt--)
    solve();
}
