// semenInRussia 2025
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n, x;
    cin >> n >> x;

    vector<int> ans(n);
    int cur = 0; // cur bit or of all numbers

    for (int k = 1; k < n; k++) {
      // if where ones in k, zeros in x, bad=break
      if ((x | k) == x) { // good
        ans[k] = k;
        cur |= k;
      } else {
        ans[k] = x;
        break;
      }
    }

    if (cur != x) {
      ans.back() = x;
    }

    for (int x : ans) {
      cout << x << " ";
    }
    cout << "\n";
  }
}
