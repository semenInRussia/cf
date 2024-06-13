// semenInRussia 2024
#include <iostream>
using namespace std;

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int a, b, c;
    cin >> a >> b >> c;
    int h = 0;
    while (a >= (1 << h))
      a -= (1 << h), h++;
    int r = (1 << h) - a;
    int v = min(b, r);
    b -= v, r -= v;
    int e = (1 << h) + a;
    r = b % e;
    h += (b + e - 1) / e;
    if (c != e)
      h = -1;
    else if (c > r)
      h++;
    cout << h << '\n';
  }
}
