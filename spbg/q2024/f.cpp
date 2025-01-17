// semenInRussia 2024
#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);

  string s;
  cin >> s;
  int n = (int)s.size();

  for (int i = 1; i < n; i++) {
    if (s[i - 1] <= s[i]) {
      s[i]++;
    }
    if (s[i] == '9' + 1) {
      s[i] = 'R';
    }
  }

  cout << s;
}
