// semenInRussia 2025
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
      int st = i;
      int d = n - 1 - st;
      if (d % (i + 1) == 0) {
        ans[i] = k;
      } else {
        ans[i] = 0;
      }
    }

    for (int x : ans) {
      cout << x << " ";
    }
    cout << "\n";
  }
}
