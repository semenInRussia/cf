// semenInRussia 2024
#include <cstdint>
#include <iostream>

using namespace std;

bool can[10];

void solve() {
  int n, d;
  cin >> n >> d;

  can[1] = 1;
  can[3] = d % 3 == 0 || n >= 3;
  can[5] = d == 5;
  can[7] = d == 7 || n >= 3;
  can[9] = d == 9 || n >= 6 || (d % 3 == 0 && n >= 3);

  for (int i = 0; i < 10; i++) {
    if (can[i]) {
      cout << i << " ";
    }
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
