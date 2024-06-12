// semenInRussia 2024
#include <iostream>
using namespace std;
using ll = long long;

struct node {
  int len = 1;
  ll ans, sum, lazy;
};

int n;
const int N = 1 << 17;
node t[2 * N];
int a[N];

void upd(node &x, int v) {
  x.lazy += v;
  x.sum += 1ll * x.len * v;
  ll a = v, b = 1ll * x.len * v;
  x.ans += (a + b) * 1ll * x.len / 2;
}
void push(int x, int len) {
  if (len > 1 && t[x].lazy) {
    ll v = t[x].lazy;
    upd(t[x * 2 + 1], v);
    upd(t[x * 2 + 2], v);
    t[x].lazy = 0;
  }
}

node combine(node a, node b) {
  return {a.len + b.len, a.ans + b.ans + b.sum * a.len, a.sum + b.sum, 0};
}

void build(int x = 0, int l = 0, int r = N) {
  if (r - l == 1) {
    t[x] = {1, 0, 0, 0};
    if (l < n)
      t[x] = {1, a[l], a[l], 0};
    return;
  }
  int m = (l + r) / 2;
  build(x * 2 + 1, l, m);
  build(x * 2 + 2, m, r);
  t[x] = combine(t[x * 2 + 1], t[x * 2 + 2]);
}

node qry(int ql, int qr, int x = 0, int l = 0, int r = N) {
  if (l >= qr || r <= ql)
    return {0, 0, 0, 0};
  if (l >= ql && r <= qr)
    return t[x];
  push(x, r - l);
  int m = (l + r) / 2;
  return combine(qry(ql, qr, x * 2 + 1, l, m), qry(ql, qr, x * 2 + 2, m, r));
}

void update(int ql, int qr, int v, int x = 0, int l = 0, int r = N) {
  if (l >= qr || r <= ql)
    return;
  if (l >= ql && r <= qr) {
    upd(t[x], v);
    return;
  }
  push(x, r - l);
  int m = (l + r) / 2;
  update(ql, qr, v, x * 2 + 1, l, m);
  update(ql, qr, v, x * 2 + 2, m, r);
  t[x] = combine(t[x * 2 + 1], t[x * 2 + 2]);
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  build();
  while (m--) {
    int t, l, r, d;
    cin >> t >> l >> r;
    if (t == 1)
      cin >> d, update(l - 1, r, d);
    else
      cout << qry(l - 1, r).ans << '\n';
  }
}
