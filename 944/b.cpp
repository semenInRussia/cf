// Copyright 2024 semenInRussia

#include <iostream>
#include <unordered_set>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9 + 7;

void solve() {
  string s;
  cin >> s;

  unordered_set<char> chs;
  for (auto ch : s)
    chs.insert(ch);
  int n = (int)s.size();

  if (chs.size() == 1)
    cout << "NO\n";
  else {
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
      if (s[i] != s[0]) {
        cout << s[i] << s.substr(0, i) << s.substr(i + 1) << endl;
        break;
      }
    }
  }
}

int main() {
  int tt;
  cin >> tt;
  while (tt--)
    solve();
}
