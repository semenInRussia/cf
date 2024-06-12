#include <iostream>
using namespace std;

const int N = (1 << 21);
int sm[2 * N], cnt[2 * N], a[2 * N], b[2 * N];
int lazy[2 * N] = {-1};

void upd(int x, int v, int len) {
  sm[x] = len * v;
  cnt[x] = a[x] = b[x] = v;
}

void push(int x, int len) {
  if (lazy[x] != -1 && len > 1) {
    int v = lazy[x];
    lazy[x] = -1;
    lazy[x * 2 + 1] = lazy[x * 2 + 2] = v;
    upd(x * 2 + 1, v, len / 2);
    upd(x * 2 + 2, v, len / 2);
  }
}

void change(int ql, int qr, int v, int x = 0, int l = 0, int r = N) {
  if (ql >= r || qr <= l)
    return;
  if (l >= ql && r <= qr) {
    upd(x, v, r - l);
    lazy[x] = v;
    return;
  }
  int m = (r + l) / 2;
  push(x, r - l);
  change(ql, qr, v, x * 2 + 1, l, m);
  change(ql, qr, v, x * 2 + 2, m, r);
  sm[x] = sm[x * 2 + 1] + sm[x * 2 + 2];
  a[x] = a[x * 2 + 1];
  b[x] = b[x * 2 + 2];
  cnt[x] = cnt[x * 2 + 1] + cnt[x * 2 + 2];
  if (b[x * 2 + 1] && a[x * 2 + 2])
    cnt[x]--;
}

int main() {
  int m;
  cin >> m;
  while (m--) {
    char ch;
    cin >> ch;
    int v = ch == 'B';
    int x, l;
    cin >> x >> l;
    x += 500000;
    change(x, x + l, v);
    cout << cnt[0] << ' ' << sm[0] << '\n';
  }
}
