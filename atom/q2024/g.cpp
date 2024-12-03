// semenInRussia 2024
// https://contest.yandex.ru/contest/69757/problems/G/
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")

using namespace std;

const int N = 3e5 + 10;
const int inf = 1e9 + 5;

#define isz(x) int(x.size())

const int L = 19;

int &setmin(int &x, int v) { return x = min(x, v); }

int id(vector<int> &t, int x) {
  return lower_bound(t.begin(), t.end(), x) - t.begin();
}

struct ST {
  vector<vector<int>> st;
  vector<int> keys;

  void build(vector<pair<int, int>> &arr) {
    int n = isz(arr);
    st.resize(L);
    for (auto &row : st) {
      row.resize(n);
    }

    sort(arr.begin(), arr.end());
    keys.resize(n);
    for (int i = 0; i < n; i++) {
      keys[i] = arr[i].first;
    }

    for (int i = 0; i < n; i++) {
      st[0][i] = arr[i].second;
    }
    for (int l = 0; l < L; l++) {
      for (int i = 0; i < n && i + (2 << l) <= n; i++) {
        st[l + 1][i] = min(st[l][i], st[l][i + (1 << l)]);
      }
    }
  }

  int qry(int l, int r) { // NOTE: that l must be already compressed
    r = id(keys, r);
    if (r - l <= 0) {
      return +inf;
    }
    int k = __lg(r - l);
    return min(st[k][l], st[k][r - (1 << k)]);
  }
};

istream &operator>>(istream &in, vector<pair<int, int>> &d) {
  for (auto &p : d) {
    in >> p.first;
  }
  for (auto &p : d) {
    in >> p.second;
  }
  return in;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  // --

  int n, x;
  cin >> n >> x;

  vector<pair<int, int>> a(n), b(n), c(n);
  cin >> a >> b >> c;

  ST at, bt, ct;
  bt.build(b);
  ct.build(c);

  int ans = +inf;
  for (int z = 0; z < 3; z++) {
    for (int i = 0; i < n; i++) {
      int l = -1, r = ans;
      int ll1 = id(bt.keys, a[i].first);
      int ll2 = id(ct.keys, a[i].first);

      // first m; cur <= x
      while (r - l > 1) {
        int m = (r - l) / 2 + l;
        int rr = a[i].first + m + 1;

        int64_t cur = 1ll * a[i].second + bt.qry(ll1, rr) + ct.qry(ll2, rr);
        if (cur <= 1ll * x) {
          r = m;
        } else {
          l = m;
        }
      }

      if (r >= 0) {
        ans = min(ans, r);
      }
    }
    if (z == 0) {
      swap(a, b);
      bt.build(b);
    } else if (z == 1) {
      swap(a, c);
      ct.build(c);
    }
  }

  cout << (ans == +inf ? -1 : ans);
}
