// semenInRussia 2024
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")

#define isz(x) int(x.size())
#define all(x) x.begin(), x.end()
#define allc(x) x.cbegin(), x.cend()

// for every phone, for every its property find:
// - next occurance of its property (min)
// - previous occurance of its property (min)
// - every property gen interval [a, b] - maximum range around phone on which
// this property is unique
//
// on query:
// - count intervals around p who inner to [l, r]
//
// complexity:
// - preprocessing is O(s log s)
// - query is O(log^2 k_{p_i})

const int S = 500'010, N = 500'010, Q = S;
vector<int> occ[S];

struct tree {
  vector<pair<int, int>> p;
  vector<vector<int>> t;
  vector<int> keys;

  inline const int id(int x) {
    return lower_bound(allc(keys), x) - keys.cbegin();
  }

  void build() {
    for (auto [l, r] : p) {
      keys.push_back(l);
    }

    sort(keys.begin(), keys.end());
    keys.resize(unique(all(keys)) - keys.begin());

    t.resize(keys.size() + 2);

    // sort queries by r, so every t[j] is already sorted
    sort(p.begin(), p.end(),
         [](auto a, auto b) { return a.second < b.second; });

    for (auto [l, r] : p) {
      add(l, r);
    }
  }

  void add(int l, const int r) {
    // for every a[0..l] add r to vector
    l = id(l) + 1;
    for (int i = l; i < isz(t); i += i & -i) {
      t[i].push_back(r);
    }
  }

  void push(const pair<int, int> a) { p.push_back(a); }

  // count in p amount of pairs [a, b] that a < l, b >= r
  //
  // NOTE: that it's same that count on [0; l) values >= r
  const int count(int l, const int r) {
    l = id(l);
    int ans = 0;
    for (int j = l; j > 0; j -= j & -j) {
      ans += t[j].cend() - lower_bound(allc(t[j]), r);
    }
    return ans;
  }
};

tree phone[N];

// for every phone save intervals like [l; r). l, r are bounds of max interval
// in which i'th property is unique
//
// answer is amount of intervals who enters into given

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  //---

  int n, m, g;
  cin >> n >> m >> g;

  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    for (int j = 0; j < k; j++) {
      int x;
      cin >> x;
      x--;
      occ[x].push_back(i);
    }
  }

  for (int x = 0; x < m; x++) {
    auto &a = occ[x];
    int e = isz(a) - 1;
    for (int j = 0; j < isz(a); j++) {
      int l = j == 0 ? -1 : a[j - 1];
      int r = j == e ? n : a[j + 1];
      phone[a[j]].push({l, r});
    }
  }

  for (int i = 0; i < n; i++) {
    phone[i].build();
  }

  int q;
  cin >> q;
  for (int j = 0; j < q; j++) {
    int l, r, p;
    cin >> l >> r >> p;
    l--, p--;
    cout << phone[p].count(l, r) << '\n';
  }
}
