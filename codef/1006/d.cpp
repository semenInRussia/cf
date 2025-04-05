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
    vector<int> a(n);
    for (int &x : a) {
      cin >> x;
    }

    pair<int, pair<int, int>> ans = {0, {0, 0}};

    for (int l = 0; l < n; l++) {
      int x = a[l];
      int bal = 0;
      for (int r = l + 1; r < n; r++) {
        if (a[r] > x) {
          bal++;
        } else if (a[r] < x) {
          bal--;
        }
        ans = min(ans, {bal, {l, r}});
      }
    }

    // for (int &x : a) {
    //   cerr << x << " ";
    // }
    // cerr << "\n";

    auto [l, r] = ans.second;
    cout << (l + 1) << " " << (r + 1) << "\n";
    // cerr << "(" << ans.first << ")\n";
  }
}
