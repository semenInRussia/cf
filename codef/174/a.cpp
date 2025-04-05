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
    cin >> n;
    n -= 2;
    vector<int> a(n);
    for (int &x : a) {
      cin >> x;
    }

    bool ok = true;

    for (int i = 1; i + 1 < n; i++) {
      if (a[i - 1] == 1 && a[i] == 0 && a[i + 1] == 1) {
        ok = false;
      }
    }

    cout << (ok ? "YES\n" : "NO\n");
  }
}
