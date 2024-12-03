// semenInRussia 2024
#include <complex>
#include <iomanip>
#include <iostream>
using namespace std;

using T = long double;
using P = complex<T>;

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    T x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    T n, xd, yd;
    cin >> n >> xd >> yd;
    for (int i = 0; i < n; i++) {
      cin >> xd >> yd >> n >> xd;
    }
    cout << fixed << setprecision(5);
    cout << abs(P(x1, y1) - P(x2, y2)) << " 0\n";
  }
}
