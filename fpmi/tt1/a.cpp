// semenInRussia 2025
#include <cstdint>
#include <iostream>

using namespace std;

const int N = 2e5, L = 20;
int a[N];
int64_t b[N];
int st[L][N];

int qry(int l, int r) {
  int k = __lg(r - l);
  return min(st[k][l], st[k][r - (1 << k)]);
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[i + 1] = b[i] + a[i];
  }

  for (int i = 0; i < n; i++) {
    st[0][i] = a[i];
  }

  for (int l = 0; l + 1 < L; l++) {
    for (int i = 0; i + (2 << l) <= n; i++) {
      st[l + 1][i] = min(st[l][i], st[l][i + (1 << l)]);
    }
  }

  pair<int64_t, pair<int, int>> ans = {0, {0, 0}};

  for (int i = 0; i < n; i++) {
    // a[i] - is minimum
    int l = i;
    int r = n + 1;
    while (r - l > 1) {
      int m = (l + r) / 2;
      if (qry(i, m) == a[i]) {
        l = m;
      } else {
        r = m;
      }
    }

    int R = l;

    l = -1;
    r = i + 1;

    while (r - l > 1) {
      int m = (r + l) / 2;
      if (qry(m, i + 1) == a[i]) {
        r = m;
      } else {
        l = m;
      }
    }

    int L = r;

    // cerr << i << ": " << L << " " << R << "\n";

    ans = max(ans, {1ll * (b[R] - b[L]) * a[i], {L, R}});
  }

  cout << ans.first << "\n";
  auto [l, r] = ans.second;

  cout << l + 1 << " " << r << "\n";
}
