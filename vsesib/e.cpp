// semenInRussia 2024
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int N = 1e4 + 10;
const int inf = 1e9 + 5;
string t[N];

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  //--
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }

  int si, sj;
  int xi, xj;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (t[i][j] == 'S') {
        si = i;
        sj = j;
      }
      if (t[i][j] == 'X') {
        xi = i;
        xj = j;
      }
    }
  }

  if (si != xi && sj != xj) {
    cout << "-1";
    return 0;
  }

  bool ok = 0;
  int ans = 0;

  if (si == xi) {
    ok = 1;
    int b = sj, a = xj;
    if (b < a) {
      swap(a, b);
    }

    for (int j = a; j < b; j++) {
      ans++;
      ok &= t[si][j] != '#';
    }
  }

  if (sj == xj) {
    ok = 1;
    int b = si, a = xi;
    if (b < a) {
      swap(a, b);
    }

    for (int j = a; j < b; j++) {
      ans++;
      ok &= t[j][sj] != '#';
    }
  }

  cout << (ok ? ans - 1 : -1);
}
