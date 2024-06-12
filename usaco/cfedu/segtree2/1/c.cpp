// semenInRussia 2024
#include <iostream>
const int maxn = 1 << 18;
int t[2 * maxn];

void push(int x, int l, int r) {
  if (t[x] != -1 && r - l > 1) {
    t[x * 2 + 1] = t[x * 2 + 2] = t[x];
    t[x] = -1;
  }
}

int get(int k, int x = 0, int l = 0, int r = maxn) {
  if (t[x] != -1)
    return t[x];
  if (r - l == 1)
    return 0;
  int m = (l + r) / 2;
  if (k < m)
    return get(k, x * 2 + 1, l, m);
  else
    return get(k, x * 2 + 2, m, r);
}

void change(int lq, int rq, int v, int x = 0, int l = 0, int r = maxn) {
  if (l >= rq || r <= lq)
    return;
  push(x, l, r);
  if (l >= lq && r <= rq) {
    t[x] = v;
    return;
  }
  int m = (l + r) / 2;
  change(lq, rq, v, x * 2 + 1, l, m);
  change(lq, rq, v, x * 2 + 2, m, r);
}

int main() {
  int n, m;
  std::cin >> n >> m;
  for (int i = 0; i < 2 * maxn; i++)
    t[i] = -1;
  while (m--) {
    int typ;
    std::cin >> typ;
    if (typ == 1) {
      int l, r, v;
      std::cin >> l >> r >> v;
      change(l, r, v);
    } else {
      int k;
      std::cin >> k;
      std::cout << get(k) << '\n';
    }
  }
}
