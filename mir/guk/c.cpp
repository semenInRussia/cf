// Copyright 2024 semenInRussia

#include <iostream>
using namespace std;

int main() {
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  int x, y;
  cin >> x >> y;

  int dy = abs(y1 - y2);
  int dx = abs(x1 - x2);

  bool ok = (dy % y + dx % x) == 0;

  // the first:
  // --- change the y

  int oy = dy / y;

  // so the first x is either +x or 0
  // after move x, we can do only even amount of steps because we need
  // to save y

  int ox1 = oy & 1;
  int ox = (dx / x) - ox1;

  ok &= !(ox & 1);

  if (ok)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;

  return 0;
}
