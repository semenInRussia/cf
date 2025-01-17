// semenInRussia 2024
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

const int N = 1e6 + 1000;
int a[N];
int64_t uni[N];
int64_t b[N], d[N];

void solve4(int n, int q) {
  map<int, int> s;
  for (int i = 0; i < n; i++) {
    s[a[i]] = i;
  }

  int l = s[1];
  int r = l + 1;

  map<int, vector<int>> v;
  v[l].push_back(1);

  for (int k = 2; k <= n; k++) {
    auto i = s[k];
    if (i + 1 > r) {
      r = i + 1;
    }
    if (i < l) {
      l = i;
    }
    if (r - l == k) {
      v[l].push_back(r - l);
    }
  }

  for (int i = 0; i < q; i++) {
    int x, l;
    cin >> l >> x;
    l--;
    // count on v[l]; >= x
    auto it = lower_bound(v[l].begin(), v[l].end(), x);

    if (it == v[l].end()) {
      cout << "-1 0\n";
    } else {
      cout << *it << " " << (v[l].end() - it) << "\n";
    }
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);

  int tg;
  cin >> tg;

  int n, q;
  cin >> n >> q;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[i + 1] = b[i] + (1ll * a[i] * a[i]);
  }

  // build uni[x] - hash of [1,2,3,..., i]
  for (int i = 1; i < n; i++) {
    uni[i] = uni[i - 1] + 1ll * i * i;
  }

  if (tg == 4) {
    solve4(n, q);
    return 0;
  }

  for (int j = 0; j < q; j++) {
    int l, x;
    cin >> l >> x;
    l--;
    int len = -1;
    int cnt = 0;

    // (r-l) * (1+(r-l))

    for (int i = max(1, x); i < n; i++) {
      bool ok = b[l + i] - b[l] == uni[i];
      cnt += ok;
      if (ok && len == -1) {
        len = i;
      }
    }

    cout << len << " " << cnt << "\n";
  }
}
