// semenInRussia 2024
#include <cstdint>
#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int m;
  cin >> m;
  string s;
  cin >> s;

  int64_t t = 0; // total sum
  for (auto c : s) {
    t += c - '0';
  }
  if (t % 3) {
    cout << "-1";
    return 0;
  }
  int ans = -1;
  for (int i = 0; i < m; i++) {
    int d = s[i] - '0';
    if (d % 2 == 0) {
      ans = i;
    }
  }

  if (ans == -1) {
    cout << "-1";
    return 0;
  }

  cout << (m - 1 - ans) << "\n";
}
