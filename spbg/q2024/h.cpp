// semenInRussia 2024
#include <algorithm>
#include <cstdint>
#include <iostream>

using namespace std;

void solve1() {
  string s;
  cin >> s;

  int sum = 0;

  for (char c : s) {
    sum += c - '0';
  }

  s[sum % 10] = '?';

  cout << s << "\n";
}

void solve2() {
  string s;
  cin >> s;

  int sum = 0;
  int r = find(s.begin(), s.end(), '?') - s.begin();

  for (int j = 0; j < 10; j++) {
    if (j != r) {
      sum += s[j] - '0';
    }
  }

  sum += (r - (sum % 10) + 10) % 10;

  cout << sum << "\n";
}

int main() {
  string typ;
  cin >> typ;

  int tt;
  cin >> tt;

  bool v = typ == "Hercule";

  while (tt--) {
    if (v == 0) {
      solve1();
    } else {
      solve2();
    }
  }
}
