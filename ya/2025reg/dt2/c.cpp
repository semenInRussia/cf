// semenInRussia 2025
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

const int N = 1 << 18;

// add on prefix, max on prefix
int64_t lazy[2 * N], t[2 * N];

void apply(int x, int64_t v) {
  lazy[x] += v;
  t[x] += v;
}

void push(int x) {
  apply(2 * x + 1, lazy[x]);
  apply(2 * x + 2, lazy[x]);
  lazy[x] = 0;
}

void add(int ql, int qr, int64_t v, int x = 0, int l = 0, int r = N) {
  if (ql <= l && r <= qr) {
    apply(x, v);
    return;
  }

  if (ql >= r || qr <= l) {
    return;
  }

  int m = (r + l) / 2;

  push(x);
  add(ql, qr, v, 2 * x + 1, l, m);
  add(ql, qr, v, 2 * x + 2, m, r);

  t[x] = max(t[2 * x + 1], t[2 * x + 2]);
}

struct enem {
  int a;
  int b;
  int c;
  int j;
};

istream &operator>>(istream &in, enem &x) { return in >> x.a >> x.b >> x.c; }

enem e[N];

bool operator<(enem s, enem t) {
  return s.a < t.a || (s.a == t.a && s.c > t.c) ||
         (s.a == t.a && s.c == t.c && s.j < t.j);
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  //---

  int n, k;
  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    cin >> e[i];
  }

  sort(e, e + n);

  for (int i = 0; i < n; i++) {
    e[i].j = i;
  }

  set<enem> s;

  auto ins = [&](enem x) {
    add(x.j, x.j + 1, x.a);
    add(x.j + 1, n, -x.c);
    s.insert(x);
  };

  auto er = [&](enem x) {
    add(x.j, x.j + 1, -x.a);
    add(x.j + 1, n, +x.c);
    s.erase(s.find(x));
  };

  sort(e, e + n, [](auto s, auto t) { return s.b < t.b; });

  int64_t ans = 1e18 + 1000;

  for (int i = 0; i < n; i++) {
    ins(e[i]);
    if ((int)s.size() >= k) {
      ans = min(ans, t[0] + e[i].b);
      er(*s.rbegin());
    }
  }

  cout << ans;
}
