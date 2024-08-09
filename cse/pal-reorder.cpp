// semenInRussia 2024
// https://cses.fi/problemset/task/1755
#include <algorithm>
#include <iostream>
using namespace std;

int cnt[29];
int main() {
  string s;
  cin >> s;
  int n = int(s.size());
  for (auto ch : s)
    cnt[ch - 'A']++;
  char ch = 0;
  int odds = 0;
  for (int c = 0; c < 29 && odds <= 1; c++) {
    if (cnt[c] & 1) {
      odds++;
      ch = c + 'A';
    }
  }
  if (odds > 1) {
    cout << "NO SOLUTION";
    return 0;
  }
  string l = "";
  for (int c = 0; c < 29; c++) {
    if (c == ch - 'A')
      cnt[c]--;
    while (cnt[c]) {
      cnt[c] -= 2;
      l += c + 'A';
    }
  }
  string ans = l;
  if (odds)
    ans += ch;
  reverse(l.begin(), l.end());
  ans += l;
  cout << ans;
}
