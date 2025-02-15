// semenInRussia 2025
#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

const int N = 2e5;
int ca[N], cb[N], t[N];
bool used[N];

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
      cin >> ca[i];
      ca[i]--;
    }

    for (int i = 0; i < n; i++) {
      cin >> cb[i];
      cb[i]--;
    }

    for (int i = 0; i < n; i++) {
      used[i] = false;
      t[ca[i]] = cb[i];
    }

    vector<int> p; // sizes of cycles

    for (int i = 0; i < n; i++) {
      int x = i;
      int sz = 0;
      while (!used[x]) {
        used[x] = true;
        x = t[x];
        sz++;
      }
      if (sz > 0) {
        p.push_back(sz);
      }
    }

    sort(p.begin(), p.end(), [](int a, int b) {
      if (a % 2 == b % 2) {
        return a < b;
      }
      if (a % 2 == 0) {
        return true;
      }
      return false;
    });

    set<int> s;
    for (int i = 1; i <= n; i++) {
      s.insert(i);
    }

    int64_t ans = 0;

    for (int sz : p) {
      if (sz == 1) {
        continue;
      }
      vector<int> row;
      bool fl = false;

      bool odd = sz & 1;
      if (odd) {
        sz--;
      }

      while (sz--) {
        auto it = fl ? s.begin() : prev(s.end());
        row.push_back(*it);
        s.erase(it);
        fl ^= 1;
      }

      // debug(row);

      sz = int(row.size());

      for (int i = 0; i < sz; i++) {
        ans += abs(row[i] - row[(i + 1) % sz]);
      }
    }

    cout << ans << "\n";
  }
}
