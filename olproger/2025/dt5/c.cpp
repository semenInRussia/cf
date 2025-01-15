// semenInRussia 2025
#include <cstdint>
#include <iostream>

using namespace std;

void solve() {
  int n, m, b;
  cin >> n >> m >> b;

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
  }

  for (int i = 1; i <= b; i++) {
    cout << i << " ";
  }
  cout << "\n";
}

int main() {
  int tt = 1;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
