// semenInRussia 2024
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

int mp[26] = {2, 2, 2, 3,  3, 3, 4, 4, 4, 5, 5, 5, 6,
              6, 6, 7, -1, 7, 7, 8, 8, 8, 9, 9, 9};

int main() {
  int n;
  cin >> n;
  map<int, int> cnt;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    int num = 0;
    while (!s.empty()) {
      char ch = s.back();
      s.pop_back();
      if (ch == '-') {
        continue;
      }
      int dig = 0;
      if (ch >= '0' && ch <= '9') {
        dig = ch - '0';
      } else {
        dig = mp[ch - 'A'];
      }
      num *= 10;
      num += dig;
    }
    cnt[num]++;
  }

  bool dups = 0;
  for (auto [_, c] : cnt) {
    if (c > 1) {
      dups = 1;
      break;
    }
  }

  if (!dups) {
    cout << "No duplicates.";
    return 0;
  }

  for (auto [num, c] : cnt) {
    if (c > 1) {
      printf("%03d-%04d %d\n", num / 10000, num % 10000, c);
    }
  }
}
