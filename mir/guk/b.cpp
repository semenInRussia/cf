// Copyright 2024 semenInRussia

#include <iostream>
using namespace std;

int main() {
  string cell;
  cin >> cell;

  int c = cell[0] - 'a';
  int d = cell[1] - '1';

  int cnt = 0;

  for (int di = -1; di <= 1; di++) {
    for (int dj = -1; dj <= 1; dj++) {
      if (di == 0 && dj == 0)
        continue;

      cnt += ((di + d) >= 0 && (di + d) < 8) && ((dj + c) >= 0 && (dj + c) < 8);
    }
  }

  cout << cnt << endl;

  return 0;
}
