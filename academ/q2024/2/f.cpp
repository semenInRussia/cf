// semenInRussia 2025
#include <cstdint>
#include <iostream>

using namespace std;

const int N = 5e5;
int a[N];
const int L = 20;
int st[N][L];

int qry(int l, int r) {
  int k = __lg(r - l);
  return max(st[l][k], st[r - (1 << k)][k]);
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i] += i;
  }

  for (int i = 0; i < n; i++) {
    st[i][0] = a[i];
  }

  for (int l = 0; l < L; l++) {
    for (int i = 0; i + (2 << l) <= n; i++) {
      st[i][l + 1] = max(st[i][l], st[i + (1 << l)][l]);
    }
  }

  int q;
  cin >> q;

  while (q--) {
    int l, x;
    cin >> l >> x;
    l--;

    int c = l;
    l--;
    int r = n + 1;

    while (r - l > 1) {
      int m = (l + r) / 2;
      if (c != m && qry(c, m) > x + c) {
        r = m;
      } else {
        l = m;
      }
    }

    cout << r - c - 1 << "\n";
  }
}
