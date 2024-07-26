// semenInRussia 2024
// https://codeforces.com/group/uQw4LhzOcG/contest/534047/problem/A
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")
#include <iostream>
using namespace std;
const int N = 1e5 + 100;
int a[N], nxt[N], cnt[N], n;

const int K = 256;
inline void recompute(int l, int r) {
  for (int i = r - 1; i >= l; i--) {
    int gr = (i / K) * K + K;
    int j = i + a[i];
    if (j >= n)
      nxt[i] = i, cnt[i] = 0;
    else if (j >= gr)
      nxt[i] = j, cnt[i] = 1;
    else {
      nxt[i] = nxt[j];
      cnt[i] = 1 + cnt[j];
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  recompute(0, n);

  int typ;
  int i, v;
  while (m--) {
    cin >> typ;
    if (typ == 0) {
      cin >> i >> v;
      i--;
      int g = i / K;
      a[i] = v;
      recompute(g * K, g * K + K);
    } else {
      cin >> i;
      i--;
      int c = cnt[i] + 1;
      while (nxt[i] != i) {
        i = nxt[i];
        c += cnt[i];
      }
      i++;
      cout << i << ' ' << c << '\n';
    }
  }
}
