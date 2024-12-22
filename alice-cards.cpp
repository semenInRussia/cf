// semenInRussia 2024
// https://codeforces.com/contest/2028/problem/D
#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;

const int N = 2e5 + 100;

int a[N][3];
int len[N];
pair<int, char> prv[N];

void solve() {
  int n;
  cin >> n;
  for (int j = 0; j < 3; j++) {
    for (int i = 0; i < n; i++) {
      cin >> a[i][j];
      a[i][j]--;
    }
  }

  len[n - 1] = 0;

  int p[3] = {n - 1, n - 1, n - 1};

  bool can = 0;

  for (int i = n - 2; i >= 0; i--) {
    can = 0;

    for (int j = 0; j < 3; j++) {
      if (a[i][j] > a[p[j]][j]) {
        can = 1;
        prv[i] = {p[j], "qkj"[j]};
        len[i] = len[p[j]] + 1;
      }
    }

    if (!can) {
      continue;
    }

    for (int j = 0; j < 3; j++) {
      if (a[i][j] < a[p[j]][j]) {
        p[j] = i;
      }
    }
  }

  if (!can) {
    cout << "NO\n";
    return;
  }

  int x = 0;

  cout << "YES\n" << len[x] << "\n";

  while (x != n - 1) {
    auto [y, c] = prv[x];
    cout << c << " " << (y + 1) << "\n";
    x = y;
  }
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
