// semenInRussia 2024
#include <algorithm>
#include <iostream>
#include <vector>

using ll = long long;

using namespace std;

const ll inf = 1e18 + 100;

struct tree {
  int sz;
  vector<ll> t;

  tree(int n) {
    sz = n;
    t.assign(4 * n, inf);
  }

  void clear() { fill(t.begin(), t.end(), +inf); }

  ll qry(int ql, int qr, int x, int l, int r) {
    if (ql <= l && r <= qr) {
      return t[x];
    }
    if (l >= qr || r <= ql) {
      return +inf;
    }

    int m = (r + l) / 2;
    return min(qry(ql, qr, 2 * x + 1, l, m), //
               qry(ql, qr, 2 * x + 2, m, r));
  }

  ll qry(int ql, int qr) { return qry(ql, qr, 0, 0, sz); }

  void change(int i, ll v, int x, int l, int r) {
    if (r - l == 1) {
      t[x] = v;
      return;
    }

    int m = (r + l) / 2;
    if (i < m) {
      change(i, v, 2 * x + 1, l, m);
    } else {
      change(i, v, 2 * x + 2, m, r);
    }
    t[x] = min(t[2 * x + 1], t[2 * x + 2]);
  }

  void change(int i, ll v) { change(i, v, 0, 0, sz); }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;

  vector<pair<pair<int, int>, int>> p(n);

  for (auto &x : p) {
    cin >> x.first.first >> x.first.second >> x.second;
    x.first.first--;
    x.first.second--;
  }

  // pref[i] - minimum cost to cover [0; i)
  // if add (l; r)
  // pref[r + 1] (min=) c_i + min(pref[l; r])

  vector<ll> pref(m, +inf);
  pref[0] = 0;

  tree t(m + 1);
  t.change(0, 0);

  sort(p.begin(), p.end(),
       [](auto a, auto b) { return a.first.second < b.first.second; });

  for (auto [lr, c] : p) {
    auto [l, r] = lr;
    if (r + 1 >= m) {
      break;
    }
    pref[r + 1] = min(pref[r + 1], c + t.qry(l, r + 1));
    t.change(r + 1, pref[r + 1]);
  }

  // suf[i] - min cost to cover (i; n)
  // suf[l - 1] (min=) c + min(suf[l; r])
  // sort by l, reversed

  vector<ll> suf(m, +inf);
  suf[m - 1] = 0;

  t.clear();
  t.change(m - 1, 0);

  sort(p.begin(), p.end(),
       [](auto a, auto b) { return a.first.first > b.first.first; });

  for (auto [lr, c] : p) {
    auto [l, r] = lr;
    if (l == 0) {
      continue;
    }
    suf[l - 1] = min(suf[l - 1], c + t.qry(l, r + 1));
    t.change(l - 1, suf[l - 1]);
  }

  ll ans = +inf;
  for (int i = 0; i < m; i++) {
    ans = min(ans, suf[i] + pref[i]);
  }

  cout << (ans == +inf ? -1 : ans);
}
