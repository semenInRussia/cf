// 2024 semenInRussia
#include <iostream>
using namespace std;
using ll = long long;

void solve() {
  int x, y;
  cin >> x >> y;
  int ans = 0;
  while (x > 0 || y > 0) {
    int free = 15;
    if (y == 1) {
      free -= 4;
      y--;
    } else if (y >= 2) {
      free -= 8;
      y -= 2;
    }

    if (x)
      x -= min(free, x);
    ans++;
  }
  cout << ans << '\n';
}

int main() {
  int tt;
  cin >> tt;
  while (tt--)
    solve();
}
