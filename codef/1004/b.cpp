// semenInRussia 2025
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>

using namespace std;

const int N = 1005;
int a[N];

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a, a + n);

    map<int, int> mp, pin;

    for (int i = 0; i < n; i++) {
      while (pin[a[i]]) {
        a[i]++;
      }
      if (mp[a[i]] == 1) {
        pin[a[i]] = 1;
      }
      mp[a[i]] ^= 1;
    }

    bool ok = true;

    for (auto [_, v] : mp) {
      if (v > 0) {
        ok = false;
      }
    }

    cout << (ok ? "YES\n" : "NO\n");
  }
}
