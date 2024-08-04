// semenInRussia 2024
#include <iostream>
using namespace std;

int main() {
  int a[] = {5, 8, 9, 12};
  int n = 4;
  int l = -1, r = n;
  int x = 0;
  while (r - l > 1) {
    int m = (r + l) / 2;
    if (a[m] <= x)
      l = m;
    else
      r = m;
  }
  cout << r;
}
