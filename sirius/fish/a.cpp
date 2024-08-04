// semenInRussia 2024
#include <iostream>
using namespace std;
const int N = 1e6;
int z[N];
int cnt[N + 10];
int main() {
  string s;
  cin >> s;
  int n = int(s.size());
  z[0] = 0;
  int l = 0, r = 1;
  for (int i = 1; i < n; i++) {
    z[i] = 0;
    if (i >= l && i < r)
      z[i] = min(r - i, z[i - l]);
    while (i + z[i] < n && s[z[i]] == s[i + z[i]])
      z[i]++;
    if (i + z[i] > r)
      l = i, r = i + z[i];
    cnt[z[i]]++;
  }
  for (int i = n; i > 0; i--)
    cnt[i - 1] += cnt[i];
  int ans = 0;
  for (int i = n - 1; i >= 0; i--)
    if (z[i] == n - i && cnt[z[i]] > 1)
      ans = n - i;
  if (ans)
    cout << s.substr(0, ans);
  else
    cout << "Just a legend";
}
