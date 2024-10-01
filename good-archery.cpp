// semenInRussia 2024
// https://codeforces.com/problemset/problem/2014/H
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")

const int N = 2e5, C = 512;
int a[N];
bool ans[N];

const int A = 1e6 + 1;
int cnt[A];
bool used[A];
vector<int> cl;

struct query {
  int l, r, idx;
  query(int _l, int _r, int _i) : l(_l), r(_r), idx(_i) {}
};

bool operator<(query a, query b) { return a.r < b.r; }

vector<query> b[N];

void solve() {
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int od[2] = {0, 0};
  auto add = [&od](int x) {
    od[cnt[x] & 1]--;
    cnt[x]++;
    od[cnt[x] & 1]++;
    if (!used[x]) {
      used[x] = 1;
      cl.push_back(x);
    }
  };
  auto rem = [&od](int x) {
    od[cnt[x] & 1]--;
    cnt[x]--;
    od[cnt[x] & 1]++;
  };

  int z = (n + C - 1) / C;
  z *= 2;
  z = min(z, N);
  for (int g = 0; g <= z; g++) {
    b[g].clear();
  }

  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    l--;
    // cout << "i=" << (l / C) << '\n';
    b[l / C].push_back(query(l, r, i));
  }
  for (int g = 0; g <= z; g++) {
    if (b[g].empty()) {
      continue;
    }
    sort(b[g].begin(), b[g].end());
    od[0] = od[1] = 0;
    int l = b[g][0].l, r = b[g][0].r;
    for (int j = l; j < r; j++) {
      add(a[j]);
    }
    for (query q : b[g]) {
      while (l < q.l) {
        rem(a[l++]);
      }
      while (l > q.l) {
        add(a[--l]);
      }
      while (r < q.r) {
        add(a[r++]);
      }
      ans[q.idx] = od[1] == 0;
    }
    for (int x : cl) {
      used[x] = cnt[x] = 0;
    }
    cl.clear();
  }
  for (int i = 0; i < q; i++) {
    cout << (ans[i] ? "YES\n" : "NO\n");
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
