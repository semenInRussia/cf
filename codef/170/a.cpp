// semenInRussia 2024
// http..
#include <iostream>
using namespace std;

int main() {
  int q;
  cin >> q;
  while (q--) {
    string s, t;
    cin >> s >> t;
    // find amount of prefix
    int mx = int(min(s.size(), t.size()));
    int pref = 0;
    while (pref < mx && s[pref] == t[pref]) {
      pref++;
    }
    int n = int(s.size());
    int m = int(t.size());
    int ans = (pref + 1) + n + m - 2 * pref;
    if (!pref) {
      ans = n + m;
    }

    cout << ans << '\n';
  }
}
