// semenInRussia 2024
#include <iostream>
using namespace std;
using ll = long long;

struct range {
  int l, r;
  ll a, d;
  ll ith(int i) { return a + d * (i - l); }
};

range extract(int l, int r, range rng) {
  return {
      l,
      r,
      rng.a + rng.d * (l - rng.l),
      rng.d,
  };
}

range operator+(range a, range b) { return {a.l, b.r, a.a + b.a, a.d + b.d}; }
range operator+=(range &a, range b) { return (a = a + b); }

const int maxn = (1 << 18);
range t[2 * maxn];
void build(int x = 0, int l = 0, int r = maxn) {
  t[x] = {l, r, 0, 0};
  if (r - l == 1)
    return;
  int m = (r + l) / 2;
  build(x * 2 + 1, l, m);
  build(x * 2 + 2, m, r);
}

void change(range rng, int x = 0, int l = 0, int r = maxn) {
  if (rng.l >= r || rng.r <= l)
    return;
  if (l >= rng.l && r <= rng.r) {
    t[x] += extract(l, r, rng);
    return;
  }
  int m = (r + l) / 2;
  change(rng, x * 2 + 1, l, m);
  change(rng, x * 2 + 2, m, r);
}

ll get(int k, int x = 0, int l = 0, int r = maxn) {
  if (r - l == 1)
    return t[x].ith(k);
  int m = (r + l) / 2;
  if (k < m)
    return t[x].ith(k) + get(k, x * 2 + 1, l, m);
  else
    return t[x].ith(k) + get(k, x * 2 + 2, m, r);
}

int main() {
  build();
  int n, m;
  cin >> n >> m;
  while (m--) {
    int t;
    cin >> t;
    if (t == 1) {
      int l, r, a, d;
      cin >> l >> r >> a >> d;
      change({l, r + 1, a, d});
    } else {
      int k;
      cin >> k;
      cout << get(k) << '\n';
    }
  }
}
