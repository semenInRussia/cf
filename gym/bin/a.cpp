// semenInRussia 2024
#include <algorithm>
#include <iostream>
using namespace std;

const int N = 2e5;
int a[N];

int main() {
  freopen("collect.in", "r", stdin);
  freopen("collect.out", "w", stdout);
  // --

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  int m;
  cin >> m;
  for (int j = 0; j < m; j++) {
    int x;
    cin >> x;
    bool ok = binary_search(a, a + n, x);
    cout << (ok ? "YES\n" : "NO\n");
  }
}
