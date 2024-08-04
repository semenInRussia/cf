// semenInRussia 2024
#include <iostream>
using namespace std;

bool check(string &s) {
  int n = int(s.size());
  for (int i = 0; i < n; i++)
    if (s[i] != s[n - i - 1])
      return false;
  return true;
}

int main() {
  string s;
  cin >> s;
  int ans = -1;
  string t;
  int n = s.size();
  for (int i = 1; i <= n; i++) {
    t.clear();
    // [n-i; n) + [0; n-i)
    t += s.substr(n - i);
    t += s.substr(0, n - i);
    if (check(t)) {
      ans = i;
      break;
    }
  }
  cout << ans;
}
