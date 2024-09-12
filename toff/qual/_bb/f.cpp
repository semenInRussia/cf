// semenInRussia 2024
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()

#pragma GCC optimize("unroll-loops,Ofast")

const int N = 1 << 19, inf = 1e9 + 5;
vector<int> e[N], t[2 * N];

void build(int x = 0, int l = 0, int r = N) {
  if (r - l == 1) {
    t[x] = e[l];
    sort(all(t[x]));
    return;
  }
  int m = (r + l) / 2;
  build(2 * x + 1, l, m);
  build(2 * x + 2, m, r);
  merge(all(t[2 * x + 1]), //
        all(t[2 * x + 2]), //
        back_inserter(t[x]));
}

// return lower_bound(v) on ends[ql] + ends[ql+1] + ... + ends[qr]
int qry(int ql, int qr, int v, int x = 0, int l = 0, int r = N) {
  if (l >= ql && r <= qr) {
    auto it = lower_bound(all(t[x]), v);
    if (it == t[x].end()) {
      return +inf;
    }
    return *it;
  }
  if (ql >= r || qr <= l) {
    return +inf;
  }
  int m = (l + r) / 2;
  return min(qry(ql, qr, v, 2 * x + 1, l, m), //
             qry(ql, qr, v, 2 * x + 2, m, r));
}

pair<int, int> p[N];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    p[i] = {a, b};
    e[a].push_back(b);
    e[b].push_back(a);
  }
  build();

  bool ok = 0;
  for (int i = 0; i < n && !ok; i++) {
    auto [l, r] = p[i];
    if (l > r) {
      swap(l, r);
    }
    if (qry(l, r, 0) < l) {
      ok = 1;
    }
    if (qry(l, r, r + 1) <= 2 * n + 1) {
      ok = 1;
    }
  }
  cout << (ok ? "YES" : "NO");
}
