// semenInRussia 2025
#include <cassert>
#include <cstdint>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")

bool eq(map<int, int> &a, map<int, int> &b) {
  vector<pair<int, int>> aa, bb;
  aa.reserve(a.size());
  bb.reserve(b.size());

  for (auto [x, c] : a) {
    if (c != 0) {
      aa.push_back({x, c});
    }
  }

  for (auto [x, c] : b) {
    if (c != 0) {
      bb.push_back({x, c});
    }
  }

  return aa == bb;
}

void solve() {
  int n;
  cin >> n;

  map<int, int> a, b;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a[x]++;
  }

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    b[x]++;
  }

  if (a == b) {
    cout << "0\n";
    return;
  }

  if (n <= 5000) {
    vector<int> v;
    for (auto [x, c] : a) {
      v.push_back(x);
      b[x] = max(0, b[x]);
    }
    for (auto [x, c] : b) {
      v.push_back(x);
      a[x] = max(0, a[x]);
    }

    vector<int> aa(a.size()), bb(b.size());
    int j = 0;
    for (auto [x, c] : a) {
      aa[j] = c;
      bb[j] = b[x];
      j++;
    }

    int ans = -1;

    assert(a.size() == b.size());

    int s1 = 0;
    for (auto [x, c] : a) {
      s1 += b[x] == c;
    }

    for (int x = 0; x < (int)b.size(); x++) {
      for (int y = 0; y < (int)a.size(); y++) {
        // swap(x, y)
        int s = s1 - int(aa[x] == bb[x]) - int(aa[y] == bb[y]) +
                int(aa[x] == bb[y]) + int(aa[y] == bb[x]);
        if (s == (int)a.size()) {
          ans = +1;
        }
      }
    }

    cout << ans;
    return;
  }

  // one swap
  int ans = -1;

  for (int z : {1, 2}) {
    (void)z;
    swap(a, b);

    bool ok = true;

    int bad = -1;
    int cnt = 0;
    int cur = -1;
    // int ans = -1;

    for (auto [x, c] : a) {
      if (c == 0) {
        continue;
      }
      if (b[x] == 0) {
        ok = false;
      }
      if (a[x] != b[x] && bad == -1) {
        cnt++;
        bad = x;
      } else if (a[x] != b[x]) {
        int y = bad;
        if (a[x] != b[y] || a[y] != b[x]) {
          ok = false;
          break;
        }
        bad = -1;
      }
    }

    if (bad != -1 || cnt > 1) {
      ok = false;
    }
    if (ok) {
      cur = +1;
    }

    // 555 => 666
    // b[x]=0, b[y]=a[x]

    cnt = 0;
    ok = false;
    int x = -1; // in a, not in b
    int y = -1; // y

    for (auto [xi, ci] : a) {
      if (ci == 0) {
        continue;
      }
      if (b[xi] == 0) {
        x = xi;
        cnt++;
      }
    }

    for (auto [xi, ci] : b) {
      if (ci == 0) {
        continue;
      }

      if (a[xi] == 0) {
        y = xi;
        cnt++;
      }
    }

    if (cnt == 2 && x != -1 && y != -1 && b[y] == a[x]) {
      ok = true;
    }
    if (ok) {
      cur = 1;
    }

    ans = max(ans, cur);
  }

  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int tt = 1;
#ifdef home
  cin >> tt;
#endif

  while (tt--) {
    solve();
  }
}
