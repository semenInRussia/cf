// semenInRussia 2024
#include <algorithm>
#include <cstdint>
#include <iostream>
using namespace std;

void solve() {
  string s;
  cin >> s;
  reverse(s.begin(), s.end());
  for (auto &c : s) {
    if (c == 'q') {
      c = 'p';
    } else if (c == 'p') {
      c = 'q';
    }
  }
  cout << s << "\n";
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
