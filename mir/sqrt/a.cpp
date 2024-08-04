// semenInRussia 2024
// https://codeforces.com/group/uQw4LhzOcG/contest/534047/problem/A
#include <iostream>
using namespace std;
const int N = 1e5 + 100, K = 315;
int a[N], nxt[N], cnt[N], n;

void recompute(int l, int r) {
  for (int i = r - 1; i >= l; i--) {
    int gr = (i / K) * K + K;
    if (i + a[i] >= n)
      nxt[i] = i, cnt[i] = 0;
    else if (i + a[i] >= gr)
      nxt[i] = i + a[i], cnt[i] = 1;
    else {
      nxt[i] = nxt[i + a[i]];
      cnt[i] = 1 + cnt[i + a[i]];
    }
  }
}

int main() {
  int m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    nxt[i] = i;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  recompute(0, n);

  while (m--) {
    int typ;
    cin >> typ;
    if (typ == 0) {
      int i, v;
      cin >> i >> v;
      i--;
      int g = i / K;
      a[i] = v;
      recompute(g * K, g * K + K);
    } else {
      int i;
      cin >> i;
      i--;
      int c = cnt[i];
      while (nxt[i] != i) {
        i = nxt[i];
        c += cnt[i];
      }
      i++, c++;
      cout << i << ' ' << c << '\n';
    }
  }
}
