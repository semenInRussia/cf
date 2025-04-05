// semenInRussia 2025
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

struct thing {
  int64_t w;
  int64_t s;
  int msk;

  thing() {}
  thing(int64_t _w, int64_t _s, int m) : w(_w), s(_s), msk(m) {}
};

void print(thing &t) { cerr << t.w << "$" << t.s; }

bool operator<(thing a, thing b) {
  if (a.w != b.w) {
    return a.w < b.w;
  }
  if (a.s != b.s) {
    return a.s < b.s;
  }
  return a.msk < b.msk;
}

template <typename T> struct st {
  const int L = 20;
  vector<vector<T>> t;

  st(vector<T> a) {
    int n = (int)a.size();
    t.resize(n);
    for (auto &row : t) {
      row.resize(L);
    }
    for (int i = 0; i < n; i++) {
      t[i][0] = a[i];
    }
    for (int l = 0; l + 1 < L; l++) {
      for (int i = 0; i + (2 << l) <= n; i++) {
        t[i][l + 1] = max(t[i][l], t[i + (1 << l)][l]);
      }
    }
  }

  T qry(int l, int r) {
    int k = __lg(r - l);
    return max(t[l][k], t[r - (1 << k)][k]);
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);

#ifndef home
  freopen("dowry.in", "r", stdin);
  freopen("dowry.out", "w", stdout);
#endif

  int n;
  cin >> n;

  int64_t L, R;
  cin >> L >> R;

  vector<pair<int64_t, int64_t>> a(n);
  for (auto &[l, r] : a) {
    cin >> l >> r;
  }

  // { weight, cost, mask }

  int m = n / 2;

  pair<int64_t, int> ans = {0, 0};

  vector<thing> v(1 << m);
  for (int b = 0; b < (1 << m); b++) {
    v[b] = {0, 0, b};
    for (int i = 0; i < m; i++) {
      if ((b >> i) & 1) {
        v[b].w += a[i].first;
        v[b].s += a[i].second;
      }
    }
    if (L <= v[b].w && v[b].w <= R) {
      ans = max(ans, {v[b].s, b});
    }
  }

  sort(v.begin(), v.end());

  vector<pair<int64_t, int>> pp(v.size());

  for (int i = 0; i < int(v.size()); i++) {
    pp[i] = {v[i].s, v[i].msk};
  }

  st p(pp);

  vector<int64_t> w(v.size());
  for (int i = 0; i < int(v.size()); i++) {
    w[i] = v[i].w;
  }

  for (int msk2 = 0; msk2 < (1 << (n - m)); msk2++) {
    int64_t w2 = 0;
    int64_t s2 = 0;
    for (int i = 0; i < n - m; i++) {
      if ((msk2 >> i) & 1) {
        w2 += a[i + m].first;
        s2 += a[i + m].second;
      }
    }

    int l = lower_bound(w.begin(), w.end(), L - w2) - w.begin();
    int r = upper_bound(w.begin(), w.end(), R - w2) - w.begin();

    if (r - l > 0) {
      auto [s1, msk1] = p.qry(l, r);
      ans = max(ans, {s1 + s2, msk1 | (msk2 << m)});
    }
  }

  cout << __builtin_popcount(ans.second) << "\n";
  for (int j = 0; j < n; j++) {
    if ((ans.second >> j) & 1) {
      cout << (j + 1) << " ";
    }
  }
}
