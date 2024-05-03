// Copyright 2024 semenInRussia

using namespace std;
#include <iostream>

// n - len
// f - first

int main() {
  int y;
  cin >> y;

  int n = 0;
  int t = y;
  while (t) {
    n++;
    t /= 10;
  }

  int m = 1;
  int rest = 0;
  int f = y;
  for (int i = 0; i < n - 1; i++) {
    rest += (f % 10) * m;
    f /= 10;
    m *= 10;
  }

  cout << (f + 1) * m - y << endl;
  return 0;
}
