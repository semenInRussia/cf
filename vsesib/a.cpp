// semenInRussia 2024
#include <cassert>
#include <iomanip>
#include <iostream>
using namespace std;

using num = long double;

void solve(num t, num T, num x) {
  auto k = (t * x) / (T - T * x + t * x);
  cout << fixed << setprecision(12);
  cout << k;
}

int main() {
  long long T, t, x;
  cin >> T >> t >> x;
  if (x * (T - t) >= T) {
    cout << "-1";
    return 0;
  }
  solve(t, T, x);
}
