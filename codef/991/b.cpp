// semenInRussia 2024
// http..
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) {
      cin >> x;
    }

    int64_t s = 0;
    int64_t s1 = 0;
    int64_t s2 = 0;
    int n1 = 0;
    int n2 = 0;

    for (int i = 0; i < n; i++) {
      s += a[i];
      if (i & 1) {
        s2 += a[i];
        n2++;
      } else {
        s1 += a[i];
        n1++;
      }
    }

    int y = s / n;
    bool ok = (s % n == 0) && (s1 % y == 0 && s1 / n1 == y) &&
              (s2 % y == 0 && s2 / n2 == y);
    cout << (ok ? "YES\n" : "NO\n");
  }
}
