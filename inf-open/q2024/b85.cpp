// semenInRussia 2024
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,fma,bmi2,tune=native")

#define isz(x) int(x.size())
#define all(x) x.begin(), x.end()

// for every phone, for every it's property find:
// 1. next occurance of its property (min)
// 2. previous occurance of its property (min)

// for it:
// 1. count on segment
//
// final complexity of preprocessing is O(s log s)

const int S = 500'100, N = 500'100, Q = S;

vector<int> occ[S], phone[N];
int answ[Q];

struct tree {
  vector<pair<int, int>> p;
  vector<vector<int>> t;
  vector<vector<int>> a;
  vector<int> keys;

  tree() {}

  int id(int x) {
    return lower_bound(keys.begin(), keys.end(), x) - keys.begin();
  }

  void build() {
    for (auto [l, r] : p) {
      keys.push_back(l);
    }
    keys.push_back(0);
    sort(keys.begin(), keys.end());
    keys.resize(unique(all(keys)) - keys.begin());

    t.resize(keys.size() * 4);
    a.resize(keys.size());

    for (auto [l, r] : p) {
      a[id(l)].push_back(r);
    }

    build(0, 0, isz(keys));
  }

  void push(pair<int, int> a) { p.push_back(a); }

  void build(int x, int l, int r) {
    if (r - l == 1) {
      sort(a[l].begin(), a[l].end());
      swap(a[l], t[x]);
      return;
    }
    int m = (r + l) / 2;
    build(2 * x + 1, l, m);
    build(2 * x + 2, m, r);
    merge(all(t[2 * x + 1]), all(t[2 * x + 2]), back_inserter(t[x]));
  }

  // count on elements of [-inf; qr) >= v
  //
  // it equals to amount of [l; r] inside p, which contain [qr; v)
  int count(int qr, int v) { return count(0, 0, isz(keys), v, 0, id(qr)); }

  int count(int x, int l, int r, int v, int ql, int qr) {
    if (l >= ql && r <= qr) {
      // count >= v
      return t[x].end() - lower_bound(all(t[x]), v);
    }
    if (r <= ql || l >= qr) {
      return 0;
    }
    int m = (r + l) / 2;
    return count(2 * x + 1, l, m, v, ql, qr) +
           count(2 * x + 2, m, r, v, ql, qr);
  }
};

tree intr[N];

// for every phone save intervals like [l; r). l, r are bounds of max interval
// in which i'th property is unique
//
// answer is amount of intervals who enters into given

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  //---

  int n, m, g;
  cin >> n >> m >> g;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    phone[i].resize(k);
    for (auto &x : phone[i]) {
      cin >> x;
      x--;
    }
    for (int x : phone[i]) {
      occ[x].push_back(i);
    }
  }

  for (int x = 0; x < m; x++) {
    auto &row = occ[x];
    for (int j = 0; j < isz(row); j++) {
      int l = j == 0 ? -1 : row[j - 1];
      int r = j == isz(row) - 1 ? n : row[j + 1];
      intr[row[j]].push({l, r});
    }
  }

  for (int i = 0; i < n; i++) {
    intr[i].build();
  }

  int q;
  cin >> q;
  for (int j = 0; j < q; j++) {
    int l, r, p;
    cin >> l >> r >> p;
    l--, p--;
    answ[j] = intr[p].count(l, r);
  }
  for (int j = 0; j < q; j++) {
    cout << answ[j] << "\n";
  }
}
