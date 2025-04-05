// semenInRussia 2025
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<vector<int>> a(k);
  for (auto &row : a) {
    int l;
    cin >> l;
    row.resize(l);
    for (int &x : row) {
      cin >> x;
      --x;
    }
    sort(row.begin(), row.end());
  }

  vector<int> p(k);

  for (int i = 0; i < k; i++) {
    p[i] = i;
  }

  do {
    vector<int> d(k), used(n);
    int cur = 0; // current minimum
    bool ok = true;
    for (int i : p) {
      int mn = a[i][0];
      d[i] = cur - mn;
      for (int x : a[i]) {
        if (x + d[i] >= n || used[x + d[i]]) {
          ok = false;
          break;
        }
        used[x + d[i]] = true;
      }
      if (!ok) {
        break;
      }
      while (cur < n && used[cur]) {
        ++cur;
      }
    }

    if (ok && *min_element(used.begin(), used.end()) == true) {
      cout << "Yes\n";
      for (int x : d) {
        cout << x << " ";
      }
      return 0;
    }
  } while (next_permutation(p.begin(), p.end()));

  cout << "No";
}
