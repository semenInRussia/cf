// semenInRussia 2024
//
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <set>
using namespace std;

const int N = 1e6;

int a[N], q[N];

void solve() {
  int n, m, k;
  cin >> n >> m >> k;

  for (int i = 0; i < m; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < k; i++) {
    cin >> q[i];
  }

  if (k == n) {
    for (int i = 0; i < m; i++) {
      cout << "1";
    }
    cout << "\n";
    return;
  }

  if (k < n - 1) {
    for (int i = 0; i < m; i++) {
      cout << "0";
    }
    cout << "\n";
    return;
  }

  int r = -1;
  for (int i = 1; i <= n; i++) {
    if (!binary_search(q, q + k, i)) {
      r = i;
      break;
    }
  }

  for (int i = 0; i < m; i++) {
    cout << (a[i] == r);
  }
  cout << "\n";
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
