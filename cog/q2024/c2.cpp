// semenInRussia 2024
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

void solve() {
  int n;
  string s;
  cin >> n >> s;

  set<int> m;
  for (int i = 0; i < n; i++) {
    m.insert(i);
  }

  int i = 0;
  while (1) {
    auto jt = m.upper_bound(i);
    if (jt == m.end()) {
      break;
    }

    int j = *jt;

    int d = abs(s[i] - s[j]);

    if (d != 1) {
      i = j;
      continue;
    }

    if (s[i] > s[j]) { // erase s[i]
      m.erase(i);
      jt = m.find(j);
      if (jt == m.begin()) {
        i = j;
      } else {
        i = *prev(jt);
      }
    } else { // erase s[j]
      m.erase(j);
    }
  }

  string ans = "";
  for (int i : m) {
    ans.push_back(s[i]);
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
