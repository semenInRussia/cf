// semenInRussia 2024
#include <cstdint>
#include <iostream>

using namespace std;

void solve() {
  int l, r;
  cin >> l >> r;

  int k = __lg(r ^ l);

  int a = (r >> k) << k;
  int b = a - 1;
  int c = a == r ? l : r;

  cout << a << " " << b << " " << c << "\n";
}

int main() {
  int tt = 1;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
