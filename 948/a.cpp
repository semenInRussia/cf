// semenInRussia 2024
#include <iostream>
using namespace std;
using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;

  int ans = 0;
  for (int a = 0; a <= n; a++) {
    int b = n - a;
    if (a - b == m)
      ans = 1;
  }
  cout << (ans ? "Yes" : "No") << '\n';
}

int main() {
  int tt;
  cin >> tt;
  while (tt--)
    solve();
}
