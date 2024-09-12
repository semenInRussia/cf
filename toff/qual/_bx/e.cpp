// semenInRussia 2024
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

using pii = pair<int, int>;

const int N = 1 << 20, K = 20;
vector<pii> t[2 * N];
int a[N];

vector<pii> combine(vector<pii> a, vector<pii> b) {
  vector<pii> c;
  merge(a.rbegin(), a.rend(), //
        b.rbegin(), b.rend(), //
        back_inserter(c));
  reverse(c.begin(), c.end());
  int j = 0;
  int sz = int(c.size());
  for (int i = 0; i < sz; i++) {
    if (i == 0 || c[j - 1].first != c[i].first) {
      c[j++] = c[i];
      continue;
    }
    c[j - 1].second += c[i].second;
  }
  c.resize(min(K, j));
  return c;
}

void update(int i, int v, int x = 0, int l = 0, int r = N) {
  if (r - l == 1) {
    a[i] = v;
    t[x] = {{v, 1}};
    return;
  }
  int m = (r + l) / 2;
  if (i < m) {
    update(i, v, 2 * x + 1, l, m);
  } else {
    update(i, v, 2 * x + 2, m, r);
  }
  t[x] = combine(t[2 * x + 1], t[2 * x + 2]);
}

// return top K nodes on range [ql; qr)
vector<pii> top(int ql, int qr, int x = 0, int l = 0, int r = N) {
  if (l >= ql && r <= qr) {
    return t[x];
  }
  if (l >= qr || r <= ql) {
    return {};
  }
  int m = (r + l) / 2;
  return combine(top(ql, qr, 2 * x + 1, l, m), //
                 top(ql, qr, 2 * x + 2, m, r));
}

void build(int x = 0, int l = 0, int r = N) {
  if (r - l == 1) {
    t[x] = {{a[l], 1}};
    return;
  }
  int m = (r + l) / 2;
  build(2 * x + 1, l, m);
  build(2 * x + 2, m, r);
  t[x] = combine(t[2 * x + 1], t[2 * x + 2]);
}

int main() {
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  build();
  for (int z = 0; z < q; z++) {
    int typ;
    cin >> typ;
    if (typ == 1) { // update
      int i, x;
      cin >> i >> x;
      i--;
      update(i, x);
      continue;
    }

    int l, r, k;
    cin >> l >> r >> k;
    auto tp = top(l - 1, r);
    tp.resize(K);
    int ans = tp[k - 1].second;
    cout << ans << '\n';
  }
}
