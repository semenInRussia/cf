// semenInRussia 2024
#include <cstdint>
#include <iostream>
using namespace std;

const int N = 2e5;
int a[N], b[N];

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }

  int ans = a[n - 1];

  for (int i = 0; i + 1 < n; i++) {
    if (a[i] > b[i + 1]) {
      ans += a[i] - b[i + 1];
    }
  }

  cout << ans << "\n";
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
