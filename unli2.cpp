// semenInRussia 2024
// https://codeforces.com/problemset/problem/2009/G1
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

struct query {
  int l, r;
  int id;
};

bool operator<(query a, query b) { return a.r < b.r; }

const int N = 2e5 + 200, inf = 1e9 + 100, C = 256;
int a[N], d[N], ans[N];
vector<query> qs[(N + C - 1) / C];

void solve() {
  int n, k, q;
  cin >> n >> k >> q;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  // find d=a_i-(i-l)
  for (int i = 0; i < n; i++) {
    d[i] = a[i] - i;
  }

  // for every [i; i+k) maintain the count of element and choose the best
  // ans[i] is answer for [i; i+k)
  map<int, int> cnt;
  multiset<int> vars;

  auto add = [&cnt, &vars](int x) {
    if (cnt[x]) {
      vars.erase(vars.find(cnt[x]));
    }
    cnt[x]++;
    vars.insert(cnt[x]);
  };

  auto rem = [&cnt, &vars](int x) {
    int k = cnt[x];
    if (k) {
      vars.erase(vars.find(k));
    }
    cnt[x]--;
    k--;
    if (k) {
      vars.insert(k);
    }
  };

  for (int i = 0; i * C <= n; i++) {
    qs[i].clear();
  }
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    l--;
    qs[l / C].push_back({l, r, i});
  }

  for (int g = 0; g * C <= n; g++) {
    if (qs[g].empty()) {
      continue;
    }
    vars.clear();
    cnt.clear();

    sort(qs[g].begin(), qs[g].end());

    int L = qs[g][0].l, R = qs[g][0].r;
    for (int i = L; i < R; i++) {
      add(d[i]);
    }
    for (auto qr : qs[g]) {
      int l = qr.l, r = qr.r, id = qr.id;
      while (L > l) {
        add(d[--L]);
      }
      while (L < l) {
        rem(d[L++]);
      }
      while (R < r) {
        add(d[R++]);
      }
      ans[id] = *vars.rbegin();
    }
  }
  for (int i = 0; i < q; i++) {
    cout << ans[i] << '\n';
  }
  cout << '\n';
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}
