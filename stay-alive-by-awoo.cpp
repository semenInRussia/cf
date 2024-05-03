// Copyright 2023 @awoo
//
// https://codeforces.com/problemset/problem/1879/F

#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    vector<int> h(n), a(n);
    forn(i, n) scanf("%d", &h[i]);
    forn(i, n) scanf("%d", &a[i]);
    int mxa = *max_element(a.begin(), a.end()) + 1;

    int l = mxa == 1 ? 0 : (__lg(mxa - 1) + 1);
    vector<vector<pair<int, int>>> st(
        l, vector<pair<int, int>>(mxa, make_pair(0, -1)));
    vector<vector<int>> st2(l, vector<int>(mxa));
    forn(i, n) {
      if (h[i] > st[0][a[i]].first) {
        st2[0][a[i]] = st[0][a[i]].first;
        st[0][a[i]] = {h[i], i};
      } else if (h[i] > st2[0][a[i]]) {
        st2[0][a[i]] = h[i];
      }
    }

    auto combine = [&st, &st2](int i, int x, int y) {
      int mx = max(st[i][x].first, st[i][y].first);
      if (mx == st[i][x].first)
        return max(st2[i][x], st[i][y].first);
      return max(st[i][x].first, st2[i][y]);
    };

    for (int j = 1; j < l; ++j)
      forn(i, mxa) {
        if (i + (1 << (j - 1)) < mxa) {
          st[j][i] = max(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
          st2[j][i] = combine(j - 1, i, i + (1 << (j - 1)));
        } else {
          st[j][i] = st[j - 1][i];
          st2[j][i] = st2[j - 1][i];
        }
      }
    vector<int> pw(mxa + 1);
    for (int i = 2; i <= mxa; ++i)
      pw[i] = pw[i / 2] + 1;

    auto getmx = [&st, &pw](int l, int r) {
      int len = pw[r - l];
      return max(st[len][l], st[len][r - (1 << len)]);
    };
    auto getmx2 = [&st, &st2, &pw, &combine](int l, int r) {
      int len = pw[r - l];
      if (st[len][l].second != st[len][r - (1 << len)].second)
        return combine(len, l, r - (1 << len));
      return max(st2[len][l], st2[len][r - (1 << len)]);
    };

    vector<long long> svmx(mxa), svmx2(mxa);
    vector<int> svwho(mxa, -1);
    for (int x = 1; x < mxa; ++x) {
      for (int l = 1; l < mxa; l += x) {
        int r = min(mxa, l + x);
        int ac = (l - 1) / x + 1;
        auto tmp = getmx(l, r);
        long long mx = tmp.first * 1ll * ac;
        int who = tmp.second;
        long long mx2 = getmx2(l, r) * 1ll * ac;
        if (who == -1)
          continue;
        if (mx > svmx[x]) {
          svmx2[x] = svmx[x];
          svmx[x] = mx;
          svwho[x] = who;
        } else if (mx > svmx2[x]) {
          svmx2[x] = mx;
        }
        svmx2[x] = max(svmx2[x], mx2);
      }
    }

    vector<long long> ans(n);
    forn(i, mxa) if (svwho[i] != -1) ans[svwho[i]] =
        max(ans[svwho[i]], svmx[i] - svmx2[i]);

    forn(i, n) printf("%lld ", ans[i]);
    puts("");
  }
  return 0;
}
