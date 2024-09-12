// semenInRussia 2024
#include <iostream>
using namespace std;
using ll = long long;

void solve() {
  int x, y;
  cin >> x >> y;
  if (x > y)
    swap(x, y);

  int ans = 1;
  for (int i = 0; i < 30; i++) {
    if ((x & 1) != (y & 1))
      break;
    ans *= 2;
    x >>= 1, y >>= 1;
  }
  cout << ans << '\n';
}

int main() {
  int tt;
  cin >> tt;
  while (tt--)
    solve();
}
