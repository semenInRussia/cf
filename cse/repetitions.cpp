// semenInRussia 2024
// https://cses.fi/problemset/task/1069
#include <iostream>
using namespace std;
int main() {
  string s;
  cin >> s;
  int ans = 1, cur = 0;
  char pch = 0;
  for (auto ch : s) {
    if (ch == pch)
      ans = max(++cur, ans);
    else
      pch = ch, cur = 1;
  }
  cout << ans;
}
