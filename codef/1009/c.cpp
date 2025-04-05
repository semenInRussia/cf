// semenInRussia 2025
#include <cstdint>
#include <iostream>

using namespace std;

// y < x
// y < x + (x ^ y)
// x < y + (x ^ y)

// x ^ y < x + y
// x ^ y > x - y

// exists position that x[i]=1, y[i]=1
// exists position that x[i]=0, y[i]=1

void solve() {
  int a;
  cin >> a;

  int b = a;
  b ^= 1 << __lg(b);
  for (int j = 0; j < 30; j++) {
    if ((~b >> j) & 1) {
      b ^= (1 << j);
      break;
    }
  }

  int ans = -1;
  int c = a ^ b;
  if (c < a + b && c > a - b) {
    ans = b;
  }

  cout << ans << "\n";
}

int main() {
  int tt = 1;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
