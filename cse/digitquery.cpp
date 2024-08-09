// https://cses.fi/problemset/task/2431
#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

const ull MAXL = 20;
ull b[MAXL], m10[MAXL], cnt[MAXL];

int main() {
  b[1] = 1, m10[0] = 1;
  ull mn = 1, mx = 10;
  for (ull i = 1; i < MAXL; i++) {
    cnt[i] = mx - mn;
    m10[i] = m10[i - 1] * 10ULL;
    mn *= 10, mx *= 10;
  }

  for (ull l = 2; l < MAXL; l++)
    b[l] = b[l - 1] + (cnt[l - 1] * (l - 1));

  ull q;
  cin >> q;

  for (ull qi = 0; qi < q; qi++) {
    ull k;
    cin >> k;

    ull beg = 0, digs;
    for (ull l = 1; l < MAXL; l++)
      if (b[l] > k) {
        digs = l - 1, beg = b[l - 1];
        break;
      }

    ull inum = (k - beg) / digs;
    ull idig = (k - beg) % digs;
    ull num = m10[digs - 1] + inum;
    cout << to_string(num)[idig] << endl;
  }
}
