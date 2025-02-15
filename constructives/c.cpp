// semenInRussia 2025
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    string s;
    cin >> n >> s;

    vector<int> b, p;

    bool fl = 0;

    for (int i = 0; i + 1 < 2 * n; i += 2) {
      p.push_back(i);
      if (s[i] == s[i + 1]) {
        continue;
      }
      // s[i] != s[i+1]: (0,1) or (1,0)
      if (s[i] == '0' + fl) {
        b.push_back(i);
      } else {
        b.push_back(i + 1);
      }
      fl ^= 1;
    }

    if (fl == 1) {
      cout << "-1\n";
      continue;
    }

    cout << b.size() << " ";
    for (int x : b) {
      cout << (x + 1) << " ";
    }
    cout << "\n";
    for (int x : p) {
      cout << (x + 1) << " ";
    }
    cout << "\n";
  }
}
